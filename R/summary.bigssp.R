summary.bigssp <- 
  function(object,fitresid=TRUE,chunksize=10000,diagnostics=FALSE,...){
    
    ndpts <- as.integer(object$ndf[1])
    if(fitresid){
      if(is.na(object$modelspec$rparm[1])){
        yhat <- object$fitted.values
      } else {
        chunksize <- as.integer(chunksize[1])
        if(chunksize<1L){stop("Input 'chunksize' must be positive integer.")}
        if(chunksize>=ndpts){
          yhat <- predict.bigssp(object)
        } else {
          xseq <- seq.int(1L,ndpts,by=chunksize)
          lenx <- length(xseq)
          if(xseq[lenx]<ndpts) {
            xseq <- c(xseq,ndpts+1)
            lenx <- lenx+1
          } else {
            xseq[lenx] <- xseq[lenx]+1
          }
          yhat <- NULL
          nxvar <- length(object$xvars)
          newdata <- vector("list",nxvar)
          names(newdata) <- names(object$xvars)
          for(mm in 1:(lenx-1)){
            chunkidx <- (xseq[mm]:(xseq[mm+1]-1))
            for(k in 1:nxvar){newdata[[k]] <- object$xvars[[k]][chunkidx,]}
            yhat <- c(yhat,predict.bigssp(object,newdata))
          } # end for(mm in 1:(lenx-1))
        } # end if(chunksize>=ndpts)
      } # end if(is.na(object$modelspec$rparm[1]))
      resid <- object$yvar-yhat
    } else{
      yhat <- resid <- NULL
    }
    if(diagnostics){
      if(!fitresid) stop("Need fitresid = TRUE when diagnostics = TRUE.")
      nterms <- length(object$tnames)
      imp <- rep(0, nterms)
      names(imp) <- object$tnames
      cfit <- yhat - object$modelspec$coef[1]
      fitss <- sum(cfit^2)
      for(k in 1:nterms){
        yk <- predict.bigssp(object, include = object$tnames[k], intercept = FALSE)
        imp[k] <- sum(yk * cfit) / fitss
      }
    } else {
      imp <- NULL
    }
    sumssp <- list(call=object$call,type=object$type,fitted.values=yhat,residuals=resid,
                   sigma=object$sigma,n=object$ndf[1],df=object$ndf[2],info=object$info,
                   converged=object$converged,iter=object$modelspec$iter,rparm=object$modelspec$rparm,
                   lambda=object$modelspec$lambda,thetas=object$modelspec$thetas,pi=imp)
    class(sumssp) <- "summary.bigssp"
    return(sumssp)
    
  }