#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Node {
    ll val;

    Node(ll v = 0) {
        val = v;
    }
};

Node merge(Node a, Node b) {
    return Node(a.val + b.val);   // CHANGE THIS
}

struct SegTree {

    int n;
    vector<Node> tree;

    SegTree(int n) {
        this->n = n;
        tree.resize(4*n);
    }

    void build(int v, int tl, int tr, vector<ll>& a) {

        if(tl == tr) {
            tree[v] = Node(a[tl]);
            return;
        }

        int tm = (tl + tr) / 2;

        build(v*2, tl, tm, a);
        build(v*2+1, tm+1, tr, a);

        tree[v] = merge(tree[v*2], tree[v*2+1]);
    }

    Node query(int v, int tl, int tr, int l, int r) {

        if(l > r)
            return Node(0);   // identity element

        if(l == tl && r == tr)
            return tree[v];

        int tm = (tl + tr) / 2;

        Node left = query(v*2, tl, tm, l, min(r,tm));
        Node right = query(v*2+1, tm+1, tr, max(l,tm+1), r);

        return merge(left, right);
    }

    void update(int v, int tl, int tr, int pos, ll val) {

        if(tl == tr) {
            tree[v] = Node(val);
            return;
        }

        int tm = (tl + tr) / 2;

        if(pos <= tm)
            update(v*2, tl, tm, pos, val);
        else
            update(v*2+1, tm+1, tr, pos, val);

        tree[v] = merge(tree[v*2], tree[v*2+1]);
    }

};


/*
only change the node and merge as per problem specifications below are some most freq
*/

//Range Sum
Node merge(Node a, Node b) {
    return Node(a.val + b.val);
}

//Range Minimum
struct Node {
    ll val;
    Node(ll v = LLONG_MAX) {
        val = v;
    }
};

Node merge(Node a, Node b) {
    return Node(min(a.val, b.val));
}

//Range Maximum
struct Node {
    ll val;
    Node(ll v = LLONG_MIN) {
        val = v;
    }
};

Node merge(Node a, Node b) {
    return Node(max(a.val, b.val));
}

//GCD/LCM
Node merge(Node a, Node b) {
    return Node(__gcd(a.val, b.val));
}

//Maximum subarray sum
struct Node {

    ll sum, pref, suff, best;

    Node(ll v = 0) {
        sum = v;
        pref = suff = best = max(v,0LL);
    }
};

Node merge(Node a, Node b) {

    Node res;

    res.sum = a.sum + b.sum;
    res.pref = max(a.pref, a.sum + b.pref);
    res.suff = max(b.suff, b.sum + a.suff);
    res.best = max({a.best, b.best, a.suff + b.pref});

    return res;
}

//Xor
struct Node{
    ll val;
    Node(ll v=0){ val=v; }
};

Node merge(Node a, Node b){
    return Node(a.val ^ b.val);
}

//Maximum with freq
struct Node{

    int mx;
    int cnt;

    Node(int m=-1e9,int c=0){
        mx=m;
        cnt=c;
    }

};

Node merge(Node a,Node b){

    if(a.mx>b.mx)
        return a;

    if(b.mx>a.mx)
        return b;

    return Node(a.mx,a.cnt+b.cnt);
}
leaf:Node(a[i],1)

//Minimum with index
struct Node{

    ll val;
    int idx;

    Node(ll v=LLONG_MAX,int i=-1){
        val=v;
        idx=i;
    }

};
Node merge(Node a,Node b){

    if(a.val<b.val) return a;
    return b;

}
leaf:Node(a[i], i)
