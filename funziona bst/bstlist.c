

struct node* insert(struct node* root, float key)
{
    /* se l'albero e vuoto torna a newnodo */
    if (root != NULL){ 
 
    
    if (key < root->key)
        root->left  = insert(root->left, key);
    else if(key>root->key)
        root->right = insert(root->right, key);
    else 
    printf("elemento presente\n"); 
}else root=newNode(key);  
    
    return root;
}
