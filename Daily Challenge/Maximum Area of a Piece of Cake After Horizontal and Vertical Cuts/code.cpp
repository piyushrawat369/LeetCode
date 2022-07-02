public int maxArea(int h, int w, int[] X, int[] Y) {
        Arrays.sort(X);
        Arrays.sort(Y);
        
        int maxX = Math.max(X[0], h - X[X.length - 1]);
        int maxY = Math.max(Y[0], w - Y[Y.length - 1]);
        
        for(int i=1; i<X.length; i++){
            maxX = Math.max(maxX, X[i] - X[i-1]);
        }
        for(int i=1; i<Y.length; i++){
            maxY = Math.max(maxY, Y[i] - Y[i-1]);
        }
        
        return (int)((long)maxX * (long)maxY % 1000000007);
    }
