rm(list=ls())
timestart<-Sys.time()
getwd()
setwd("E:/r")
##install.packages("")
library(readxl)
library(jiebaR)
library(plyr)
library(wordcloud2)
library(readr)
ps_article <- read_csv("ps_article2-0.csv")
##head(ps_article)
##str(ps_article)
posword <- read_csv("pos.csv")
negword <- read_csv("neg.csv")
pweight <- posword$X2
nweight <- negword$Y2
pos <- posword$X1
neg <- negword$Y1
mydict <- c(t(pos),t(neg))
engine <- worker()
new_user_word(engine, mydict)

##head(segwords)

segwordsfun <-function(target_words){
  target_words = target_words[grepl("[\u4E00-\u9FA5]$",target_words)==TRUE]
  target_words = target_words[(nchar(target_words)>=2)==TRUE]
  return(target_words)
}

fun <- function(x,y,myweight) {
  #return(myweight[which(x[which(x %in% y)] %in% y)])
  #sum(x %in% y)
  #x %in% y
  myweight[match(x[which(x %in% y)],y)]
  }
getEmotionalType <- function(x,pos,neg,pweight,nweight,id,title){
  pos.weight <- sapply(llply(x,fun,pos,pweight),sum)
  neg.weight <- sapply(llply(x,fun,neg,nweight),sum)
  total <- pos.weight - neg.weight
  longsize2 <- sapply(x,length)
  frequency1 <- total / longsize2
  frequency1[which(is.na(frequency1))]<-0
  info_flag<-frequency1>0.15
  info_flag[which(frequency1< -0.21)]<-2
  info_flag[which(((pos.weight<30) + (neg.weight<30))==2)]<-0
  info_flag[abs(total)<25]<-0

  return(data.frame(id,info_flag,pos.weight,neg.weight,frequency1))
}
##
segwords <- sapply(ps_article$content, segment, engine)
segwords2 <- sapply(segwords,segwordsfun)
score <- getEmotionalType(segwords2, pos, neg , pweight , nweight , ps_article$id,ps_article$title)
write.csv(score1,file="score.csv",quote=F,row.names = F)
