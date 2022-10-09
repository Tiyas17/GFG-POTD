bool isPrime(int n)
	    {
	        if(n<2)
	        {
            return false;
	        }
	        for(int i=2;i<=sqrt(n);i++)
	        {
	            if(n%i==0)
	            {
	                return false;
	            }
	            
	        }
	        return true;
	    }
	    
		int NthTerm(int N){
		    // Code here
		    int i=0;
		    while(!isPrime(N+i) && !isPrime(N-i))
		    {
		        i++;
		    }
		    return i;
		    
		}
