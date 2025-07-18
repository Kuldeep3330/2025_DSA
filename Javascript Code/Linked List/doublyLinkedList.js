class Node{
    constructor(data){
        this.data=data
        this.next=null
        this.prev=null
    }
}

// Traverse Forward
function traverseUP(head){
    while(head!==null){
        console.log(head.data);
        head=head.next        
    }
} 

//traverse down
function traverseDown(tail){
    while(tail!==null){
        console.log(tail.data);
        tail=tail.prev        
    }
}

//insert at begin in DLL
function insertAtBeg(head, x) {
    let temp = new Node(x);
    if (head !== null) {
        temp.next = head;
        head.prev = temp;
    }
    return temp;  // New head
}


//insert At end of DLL
function insertAtEnd(head, x){
    let temp= new Node(x)
    if (head === null) return temp;
    let curr=head
    while(curr.next!== null){
        curr=curr.next
    }
    curr.next=temp
    temp.prev=curr
    return head
}

//delete at the beginning of DLL
function deleteHead(head) {
    if (head === null) return null;

    let newHead = head.next;
    if (newHead !== null) {
        newHead.prev = null;
    }
    return newHead;
}

//delete at the end of DLL
function deleteLast(head){
    if (head === null) return null;

    if (head.next === null) {
        return null;
    }
    let curr= head
    while(curr.next.next!==null){
        curr=curr.next // 10 20 30 40
    }
    curr.next.prev=null
    curr.next=null
    return head
}

//reverse a doubly linked list
function reverseDLL(head) {
    if (head === null || head.next === null) return head;

    let curr = head;
    let prev = null;

    while (curr !== null) {
        // Swap next and prev
        let temp = curr.prev;
        curr.prev = curr.next;
        curr.next = temp;

        // Move to next node (which is prev now)
        prev = curr;
        curr = curr.prev;
    }

    return prev; // new head
}

let head= new Node(10)
let temp1= new Node(20)
let temp2= new Node(30)
head.next=temp1
temp1.prev= head
temp1.next= temp2
temp2.prev= temp1

// head= insertAtBeg(head, 5)
// head= insertAtEnd(head, 40)
// head= deleteHead(head);
// head= deleteLast(head)

head= reverseDLL(head);

traverseUP(head)

// let tail=head
// while(tail.next!==null){
//     tail=tail.next
// }

// traverseDown(tail)