// [[Rcpp::depends(RcppArmadillo)]]

#include <RcppArmadilloExtensions/sample.h>

using namespace Rcpp ;


void set_seed(double seed) {
  Rcpp::Environment base_env("package:base");
  Rcpp::Function set_seed_r = base_env["set.seed"];
  set_seed_r(std::floor(std::fabs(seed)));
}

// [[Rcpp::export]]
NumericVector sample_vec( NumericMatrix x, 
                      int size,
                      bool replace, 
                      NumericVector prob,
                      double seed
) {
  set_seed(seed);  
  NumericVector x1 = x(0, _);
  
  NumericVector ret = RcppArmadillo::sample(x1, size, replace, prob) ;
  return ret;
}

// [[Rcpp::export]]
double inner2(arma::vec x,
               arma::vec y
) {
  arma::mat ip = x.t() * y ;
  return(ip(0)) ;
}

// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//

/*** R
set.seed(10)
x = matrix(rbinom(20, size = 10, prob = 0.8), 4, 5)
set.seed(10)
sample.r <- sample(x[1, ], N, replace=T, prob = c(.2, .3, .2, .1, .5) )
sample.c <- sample_vec(x, N, replace=T,prob = c(.2, .3, .2, .1, .5) , seed = 10L)

print(identical(sample.r, as.integer(sample.c) ))

vec <- rnorm(1000)
inner2(vec, vec)
*/
