
class Segtree{
public:
	vector<long long>tree,a,lazy;	
	Segtree(int n, vector<long long>&a){
		tree.resize(4*n,0);
		lazy.resize(4*n,0);
		this->a=a;
	}
	//push down lazy updates
	void prop(int i){
		lazy[2*i]+=lazy[i];
		lazy[2*i+1]+=lazy[i];
		lazy[i]=0;
	}
	//tree update operation
	void ops(int id){
		tree[id]=min(tree[id*2]+lazy[2*id],tree[id*2+1]+lazy[2*id+1]);
	}
	//tree build
	void build(int id, int l,int r){
		if(l==r){
			tree[id]=a[l];
			return;
		}
		int m=(l+r)/2;
		build(id*2,l,m);
		build(id*2+1,m+1,r);
		ops(id);
	}
	long long query(int id, int x, int y, int l ,int r){
		if(y<l||x>r)
			return 1e18;
		if(l>=x&&r<=y)
			return tree[id]+lazy[id];
		int m=(l+r)/2;
		prop(id);
		long long left=query(id*2,x,y,l,m);
		long long right=query(id*2+1,x,y,m+1,r);
		ops(id);
		return min(left,right);
	}
	void update(int id,int x, int y, int val, int l , int r){
		if(y<l||x>r)
			return ;
		if(l>=x&&r<=y){
			lazy[id]+=val;
			return;
		}
		prop(id);
		int m=(l+r)/2;
		update(id*2,x,y,val,l,m);
		update(id*2+1,x,y,val,m+1,r);
		ops(id);
	}
};

//Query->seg.query(1,x,y,0,n-1)
//Update->seg.update(1,x,y,0,n-1)



