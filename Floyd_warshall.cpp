for (int i=0;i<numCourses;i++)vis[i][i]=1;
for (int k=0;k<numCourses;k++){
    for (int i=0;i<numCourses;i++){
        for (int j=0;j<numCourses;j++){
            if (vis[i][k]!=INT_MAX && vis[k][j]!=INT_MAX){
                vis[i][j]=min(vis[i][j],vis[i][k]+vis[k][j]);
            }
        }
    }
}
