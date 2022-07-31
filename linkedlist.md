# linkedlist
## `delete nth node from end`
- move fast to the nth node
- check if n is the last node then return the node after head
- else move fast to the n+1 node
- then slow=head and keep iterating until fast is the last node i.e last->next = NULL
- slow->next=slow->next->next;

---

## `merge 2 sorted list`
- res= node(-1);
- temp=res
- while l1 and l2
-  if l1 < l2 temp->next=l1 or viceversa and l1->nxet and t->next

---

## `Merge K sorted list`
- make a priority queue as shown below
```cpp
struct compare {
        bool operator()(const ListNode* l, const ListNode* r){
            return l->val > r->val;
        }
    };

priority_queue<ListNode *, vector<ListNode *>, compare> q;
```
- add heads of all lists
- then iterate till q empty
    - t = q.top
    - q.pop
    - `if(t->next)q.push(t->next)`
    - ans->next = t
    - `t->next=NULL` too terminate t

---
## `swap alternate nodes`
`question`
![](pics\llq1.png)
![](pics\altrepl-ll.png)

---

## `reverse k groups`

![](pics\llq-2.png)
![](pics\llq2.png)
```
curr->next=next;  // 1
next->next=pre->next // 2
pre->next=next;  // 3
next=curr->next; // changing next for next loop
```
---

## `Remove Duplicates from Sorted List`
- while curr
    - if `pre->val==curr->val`
        - curr=curr->next
    - else
        pre->next=curr
        pre=curr
        curr=curr->next;
- `pre->next=curr`

---
> `Flatten Binary Tree to Linked List `
![](pics\llq3.png)
```
next=NULL;
func(){
    if(root==NULL)return;
    flatten(root->right);
    flatten(root->left);
    root->right=next;
    root->left=NULL;
    next=root;
}
```
---
## `copy of linked list`

- create new nodes with same vall as original as shown
![](pics\llcpy.png)
- connect the random mapppings of copy nodes
    - if l1->random == `NULL` then l2->random = NULL;
- disconnect the orig and copy from each other
  - l1->next=l2->next;
  - l2->next=l2->next->next; // if l2->next!=NULL
  l1=l1->nex;
---  

## `linked list cycle`
![](pics\lla4.png)

---
## `insertion sort`
![](pics\llisa.png)

---
## `intersection of 2 ll`
![](pics\llint.png)

---
## `reverse ll `
![](pics\llrev.png)

---
## `Split Linked List in Parts`
![](pics\llq4.png)
- find size of ll
- find `num of nodes` in each partition and `extra` left over
- while curr
    - add curr to ans ,currlen++
    - for i=1 to num of nodes => curr=curr-> next, currlen++
    - if extra>0 add one more node by curr=curr-> next, currlen++
    - temp=curr, curr=curr->next, `temp=>next=NULL`
- while currlen < k when no. of partition greater than size
   - add NULL to ans