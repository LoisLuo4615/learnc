##kmeans-一维-多维
## author leaf

# distance from all samples to K centers
dd<-function(x,xk){
k<-nrow(xk)
n<-nrow(x)
d<-matrix(1:(k*n),k)
for(i in 1:k){
r<-t(t(x)-xk[i,])
d[i,]<-apply(r,1,function(x) sqrt(x %*% x))
}
t(d)
}
# update K centers
updatak<-function(x,oldkc){
d<-dd(x,oldkc)
newkg<-apply(d,1,which.min)
newkc <- tapply(1:nrow(x),newkg,function(i) colMeans(x[i,]))
list(newkc=matrix(unlist(newkc),nrow(oldkc),byrow=T),newkg=newkg)
}

kmeans_step_2dim <- function(Kcenters_old,data,cex=0.5){
  plot(data,cex=cex,pch=19,col=updatak(data,Kcenters_old)$newkg+1)
  points(Kcenters_old,col=5,cex=cex+1,pch=2)
  Kcenters_new <- updatak(data,Kcenters_old)$newkc
  points(Kcenters_new,col=6,cex=cex+1,pch=2)
  legend(x=4.2,y=4.3,legend=c("old","new"),pch=2,cex=1,col=5:6)
  old_new_diff <- apply(Kcenters_old-Kcenters_new,1,function(x) sqrt(x%*%x))
  Kcenters_old <- Kcenters_new
  stop_or_not <- all(old_new_diff < 0.001)
  list(Kcenters_new=Kcenters_new,
       old_new_diff=old_new_diff,
       stop=stop_or_not)
}
# Clickable and Stepwise Kmeans
Clickable_Stepwise_Kmeans <- function(data,centers_old,k){
  j <- 1
  repeat{
    step <- kmeans_step_2dim(centers_old,data=data)
    title(main=paste("step:",j))
    centers_old <- step$Kcenters_new
    locator(1)
    if(step$stop){
      kmeans_step_2dim(centers_old,data=data)
      title(main=paste("iteration convergences on step:",j))
      break
    }
    j <- j+1
  }
newkg<-updatak(data,centers_old)$newkg
newkg
}

x<-iris[,1:4]
oldkc<-as.matrix(x[c(1,51,130),])
##kmeans_step_2dim(oldkc[,1:2],x[,1:2])
newkg1<-Clickable_Stepwise_Kmeans(x[,1:2],oldkc[,1:2],3)
sum(newkg1==rep(1:3,each=50))/150
##准确率0.8133333
newkg2<-Clickable_Stepwise_Kmeans(x[,2:3],oldkc[,2:3],3)
sum(newkg2==rep(1:3,each=50))/150
##准确率0.9133333
newkg3<-Clickable_Stepwise_Kmeans(x[,3:4],oldkc[,3:4],3)
sum(newkg3==rep(1:3,each=50))/150
##准确率0.9466667
newkg4<-Clickable_Stepwise_Kmeans(x,oldkc,3)
sum(newkg4==rep(1:3,each=50))/150
##准确率0.8933333


