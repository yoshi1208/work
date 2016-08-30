/* 初期化 (TrInit)
 * ノードの追加(TrAddNode)
 * ノードの探索(TrSearchNode)
 * ノードの削除(TrDeleteNode)
 */

typedef int TREE_KEY;
typedef double TREE_ITEM;

struct NODE{
	TREE_KEY key;
	TREE_ITEM data;
	struct NODE *left;
	struct NODE *right;
};

#define NULL 0
struct NODE *root = NULL;

void TrInitNode(struct NODE *pos){
	if(pos->left != NULL){
		TrInitNode(pos->left);
	}
	if(pos->right != NULL){
		TrInitNode(pos->right);
	}
	free(pos);
}
void TrInit(){
	if( root != NULL){
		TrInitNode(root);
	}
}

void TrAddNode(TREE_KEY key,TREE_ITEM data){
	struct NODE *new_node;
	new_node = (struct NODE *)malloc(sizeof(struct NODE));
	new_node->key=key;
	new_node->data = data;
	new_node->left = new_node->right =NULL;

	if(root==NULL){
		root = new_node;
	}else{
		struct NODE *pos = root;
		while(pos != NULL){
			if(key <=pos->key){
				if(pos->left==NULL){
					pos->left = new_node;
					pos = NULL;
				}else{
					pos = pos->left;
				}
			}else{
				if(pos->right ==NULL){
					pos->right =new_node;
					pos = NULL;
				}else{
					pos=pos->right;
				}
			}
		}
	}
}

TREE_ITEM TrSearchNode(TREE_KEY key){
	struct NODE *pos = root;
	while(pos != NULL && pos->key != key){
		if(key <= pos ->key){
			pos=pos->left;
		}else{
			pos=pos->right;
		}
	}
	if (pos !=NULL){
		return pos->data;
	}else{
		printf("Not found!\n");
		return 0;
	}
}

void TrOutput(struct NODE *pos){
	if(pos->left != NULL){
		TrOutput(pos->left);
	}
	printf("%d: %.2f\n",pos->key,pos->data);
	if(pos ->right !=NULL){
		TrOutput(pos->right);
	}
}

void TrDeleteNode(TREE_KEY key){

	struct NODE **pos = &root;
	struct NODE *delete_node;
	while(*pos != NULL && (*pos)->key != key){
		if(key <= (*pos)->key){
			pos = &((*pos)->left);
		}else{
			pos = &((*pos)->right);
		}
	}
	if(*pos == NULL) return;
	delete_node =*pos;

	if((*pos)->right ==NULL){
		if((*pos)->left == NULL){
			/* 子ノードがない場合 */
			*pos =NULL;
		}else {
			/* left側のみ子ノードを持つ場合 */
			*pos = (*pos)->left;
		}
	}else{
		if((*pos)->left ==NULL){
			/*right側のみ子ノードを持つ場合 */
			*pos = (*pos)-> right;
		}else{
			/* left,right側ｇともに子ノードを持つ場合 */
			struct NODE **largemin = &((*pos)->right);
			while((*largemin)->left != NULL){
				largemin =&((*largemin)->left);
			}
			*pos = *largemin;
			*largemin =(*largemin)->right;
			(*pos)->left =delete_node->left;
			(*pos)->right = delete_node ->right;
		}

	}

	free(delete_node);
}

void list0501(){
	int i;
	TREE_ITEM found;

	TrInit();
	TrAddNode(4,14);
	TrAddNode(7,17);
	TrAddNode(6,16);
	TrAddNode(2,12);
	TrAddNode(5,10);
	for(i=1;i<=4;i++){
		printf("SerachNode(%d)= ",i);
		found=TrSearchNode(i);
		printf("%.2f\n",found);
	}
	printf("----ALL Output-----\n");
	TrOutput(root);
	printf("delete \n");
	TrDeleteNode(6);

	printf("----ALL Output-----\n");
	TrOutput(root);
	TrDeleteNode(3);
	TrDeleteNode(4);
	TrDeleteNode(5);


	printf("----ALL Output-----\n");
	TrOutput(root);
	TrDeleteNode(2);
	TrDeleteNode(7);
	TrOutput(root);


}

