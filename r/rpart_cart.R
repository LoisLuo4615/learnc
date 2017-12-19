
rm(list=ls())
setwd('E:/cart')
library(rpart.plot)
library(rpart)
library(readr)

X_train<- read_csv('X_train.csv',col_names = FALSE)
Y_train<- read_csv('y_train.csv')

Y_train<-Y_train+1
x_train<-X_train[1:60000,]
y_train<-Y_train[1:60000,1]
fit <- rpart(y_train~., data=cbind(x_train,y_train), method="class")
rpart.plot(fit, compress = TRUE)

X_test<- read_csv('X_test.csv',col_names = FALSE)
y_test<- read_csv('y_test.csv')
y_test<-y_test+1

#X_test<-X_test[1:2000,]
#y_test<-y_test[1:2000,1]

result <- predict(fit,X_test,type="class") 
source("count_result.R")

count_result <- function(result,data_test){
  n <- length(result)
  count_right <- 0
  i <- 1
  for (i in 1:n){
    if (result[i]==data_test[i,1]){
      count_right = count_right+1
    }
  }
  print(count_right/n)
}

count_result(result,cbind(y_test))
