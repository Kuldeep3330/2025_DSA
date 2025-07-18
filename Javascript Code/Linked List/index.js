class Node{
    constructor(data){
        this.data=data
        this.next=null
    }
}

function traverse(head){
    while(head!=null){
        console.log(head.data);
        head=head.next;        
    }
}

function sortedInsert(head, x){
    const temp= new Node(x)
    if(head==null){
        return temp;
    }
    if(head.data>x){
        temp.next=head;
        return temp;
    }
    let curr=head
    while(curr.next!=null && curr.next.data<x){
        curr=curr.next
    }
    temp.next=curr.next
    curr.next=temp
    return head
}

function middleOfLL(head){
    let slow=head
    let fast=head
    while(fast!=null && fast.next!=null){
        slow=slow.next
        fast=fast.next.next;
    }
    return slow.data
}

function nthFromEnd(head, n){
    let fast=head
    while(n!=0){
        fast=fast.next
        n--
    }
    let slow=head
    while(fast!=null){
        slow=slow.next
        fast=fast.next
    }
    return slow.data
}

function reverseLL(head){
    let curr=head;
    let prev=null;
    while(curr!=null){
        let next=curr.next
        curr.next=prev;
        prev=curr
        curr=next;
    }
    return prev;
}

function removeDups(head){
    let curr=head
    while(curr!=null && curr.next!=null){
        if(curr.data==curr.next.data){
            curr.next=curr.next.next;
        }
        else{
            curr=curr.next;
        }
    }
}

let head= new Node(10);
head.next= new Node(20);
head.next.next= new Node(20);
head.next.next.next= new Node(30)
head.next.next.next.next= new Node(30)
head.next.next.next.next.next= new Node(30)
head.next.next.next.next.next.next= new Node(40)

removeDups(head);
// sortedInsert(head, 25)
// head=reverseLL(head)
// let middle= middleOfLL(head)
// console.log(nthFromEnd(head, 2));

// console.log(middle);

traverse(head)