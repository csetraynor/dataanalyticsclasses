## Solutions for cs910 lab2

## Exercise 5
abalone <- read.csv("abalone.data", header =F)
for (i in 2:7) {
  for (j in i+1:(8-i)) {
    if (cor(abalone[i],abalone[j])>0.95) {
      print(cor(abalone[i],abalone[j]))
    }
  }
}

## Exercise 6 

abaloneM <- subset(abalone, V1=="M")
abaloneF <- subset(abalone, V1=="F")
abaloneI <- subset(abalone, V1=="I")
plot(ecdf(abaloneM$V9), xlab="Rings", verticals=TRUE,
     col="green", pch=" ", ann=FALSE)
lines(ecdf(abaloneF$V9), verticals=TRUE,col="blue",pch=" ")
lines(ecdf(abaloneI$V9), verticals=TRUE, col="red",pch=" ")
legend("bottomright",c("Male", "Female", "Infant"),
        col=c("green", "blue", "red"), lty=1, bty="n")
title(main="CDFs of rings in abalone data")
