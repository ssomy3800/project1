#ifndef __TREENODE_H__
#define __TREENODE_H__
#include <iostream>
#include <cstdlib>
#include "board.h"
#include <queue>
#include <stack>

using namespace std;

class treeNode{
  public:
  
  //constructor
    treeNode(){
    numChildren = 0;
    capChildren = 100;
    data = board();
    parent = new btNode;
    children = new btNode*[capChildren];
    }
  
  //copy constructor
    treeNode(btNode input){
      
     numChildren = input.numChildren;
     capChildren = input.capChildren;
     data = input.data;
      
     parent = input.parent;
      
     children = new btNode*[capChildren];
     for(int i = 0; i< input.numChildren;i++){ 
      children[i] = input.children[i]; 
     }
      
    }
  
  void setChild( treeNode entry, int pos ){   children[pos] = entry; }
  
 
  void addChild( treeNode entry ){
     
     children[numChildren] = entry;
      numChildren++;
   }
  
  treeNode** getChild(int y){return children [y];}
  
  
  treeNode** getAllChild(){
     
     for( int i = 0; i<numChildren;i++){
       
        return children[i];}
     
   }
  
  void generateChild(treeNode* inParent){
     
for(int i=0; i< 8;i++){
        for(int j=0; j<8; j++){
      
          
           if(inParent.data.winningState()) break; //check to see if the parent's board is already a winning state. 
          
           if(inParent.data[i][j]==2){ // we look for the 2 that is cloest to the oppoenet's edge becuase it is the 2 that is closest to wining
     
            
            //If it can jump down it will jump. Jump has higher priority than move. It will only try to move if it can't jump.
            
            //Jump Right Down 
               if(inParent.data.canJumpRightDown(i,j)) 
                { 
                 treeNode tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)
                 
                 tempNode.data.jumpRightDown(); // Make the move with the tempNode
                 
                 inParent.addChild(tempNode); //add the tempNode to the parent's children
                }
            
            //Jump Left Down
             if(inParent.data.canJumpLeftDown(i,j)) 
                { 
                 
                 treeNode tempNode = inParent; // store the parent state to tempNode before making the move 
                 
                 tempNode.data.jumpLeftDown(); // Make the move with the tempNode
                 
                 inParent.addChild(tempNode); //add the tempNode to the parent's children
                }
            
            //If it can move down it will move.
            
            //Move Right Down 
             if(inParent.data.canMoveRightDown(i,j)) //
               
               {  treeNode tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)
                 
                 tempNode.data.moveRightDown(); // Make the move with the tempNode
                 
                 inParent.addChild(tempNode); //add the tempNode to the parent's children
               
               } 
            
             //Move Left Down
             if(inParent.data.canMoveLeftDown(i,j)) //
               
               {  treeNode tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)
                 
                 tempNode.data.moveLeftDown(); // Make the move with the tempNode
                 
                 inParent.addChild(tempNode); //add the tempNode to the parent's children
               
               } 
            
           }
    }
}    


for(int i = 7; i < 0; i--){
	for(int j = 7; j < 0; j--){
           if(inParent.data[i][j]==1) // look for the 1 that is cloest to the opponent's side
          {
            
            //If it can jump up it will jump. Jump has higher priority than move. It will only try to move if it can't jump.
            
            //Jump Right Up
               if(inParent.data.canJumpRightUp(i,j)) 
                { 
                 treeNode tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)
                 
                 tempNode.data.jumpRightUp(); // Make the move with the tempNode
                 
                 inParent.addChild(tempNode); //add the tempNode to the parent's children
                }
            
            //Jump Left Up
             if(inParent.data.canJumpLeftUp(i,j)) 
                { 
                 
                 treeNode tempNode = inParent; // store the parent state to tempNode before making the move 
                 
                 tempNode.data.jumpLeftUp(); // Make the move with the tempNode
                 
                 inParent.addChild(tempNode); //add the tempNode to the parent's children
                }
            
            //If it can move down it will move.
            
            //Move Right Up
             if(inParent.data.canMoveRightUp(i,j)) //
               
               {  treeNode tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)
                 
                 tempNode.data.moveRightUp(); // Make the move with the tempNode
                 
                 inParent.addChild(tempNode); //add the tempNode to the parent's children
               
               } 
            
             //Move Left Up
             if(inParent.data.canMoveLeftUp(i,j)) //
               
               {  treeNode tempNode = inParent; // store the parent state to tempNode before making the move (called the copy constructor)
                 
                 tempNode.data.moveLeftUp(); // Make the move with the tempNode
                 
                 inParent.addChild(tempNode); //add the tempNode to the parent's children
               
               } 
            
           }
          
          
    }
}
    
    
   }
           
  treeNode** bfs(treeNode* inParent)
  {  
    queue<treeNode> bfsQueue;
    bfsQueue.push(inParent);
    
    while( !bfsQueue.empty() && !bfsQueue.front().data.winningState())
    {
      genChild(bfsQueue.front()); //if the front Node in queue is not in a winning state, then generate all children of this Node.
      
        for(int i=0;i<bfsQueue.front().numChildren;i++)
          {
           bfsQueue.push(bfsQueue.front()* children [i]); // push all the generated children of inParent into the queue
          }
      
      if(bfsQueue.front().data.winningState())
      {
        return bfsQueue.front();      
      }
      
      bfsQueue.pop();   // now we can pop the front Node that is not in a winning state.
     
    }      
  }
              
  treeNode** dfs(treeNode* inParent)
    
{   
    
    stack<board> dfsStack;
    
    stack.push(inParent);
    
    while( !dfsStack.top().winningState())
   {
     genChild(dfsStack.top()); //generate all the children top the top item on the stack.
      
        for(int i=0;i<dfsStack.top().numChildren;i++)
          {
           dfsStack.push(dfsStack.top()* children [i]); // push all the generated children of inParent into the stack
          }
               
      if(dfsStack.top().data.winningState())
      {
        return dfsStack.top();      
      }
      
      dfsStack.pop();
      
   }
}
           
  private:
    board data;
    size_t numChildren;
    size_t capChildren;
    treeNode *parent;
    treeNode **children;
};

#endif
