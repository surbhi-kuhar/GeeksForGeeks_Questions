We will be given k, root of the tree and node as input. We have to return kth ancestor of the node.


The approach that comes to my mind is given in the steps below :
1. Search for the node and store the parent of every node in an unordered map during this process.
2. As soon as we find the node, start finding the kth ancestor from the map.

Example :  k = 2 , node = 4 
Out : 1     2nd ancestor of 4 is 1.
  
            1
           / \
          2   3
         / \
        4   5

  We will start searching for 4 and during that we will store parent of each node .

  UNORDERED_MAP
  1 --> -1
  2 -->  1
  4 -->  2

  We found 4 . Now, we have to search for kth ancestor using this unordered_map.

  parent of 4 is 2 .   1st ancestor
  parent of 2 is 1 .   2nd ancestor

Code for finding kth ancestor using map.

  
  int ans=0;
  while(k--){
      ans=mp[node];
      node=ans;
  }
  return ans;


  
