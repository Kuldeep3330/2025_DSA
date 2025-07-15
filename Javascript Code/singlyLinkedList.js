class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

function traverse(head) {
    while (head !== null) {
        console.log(head.data);
        head = head.next;
    }
}

// Insert at beginning
function insertAtBeg(head, x) {
    let temp = new Node(x);
    temp.next = head;
    return temp;
}

//insert at end
function insertAtEnd(head, x){
    let temp= new Node(x)
    if(head===null) return temp
    let curr= head
    while(curr.next!==null){
        curr=curr.next
    }
    curr.next=temp
    return head
}

//insert at given position
function insertAtGvnPos(head, pos, x){
    let temp= new Node(x)
    if(pos===1){
        temp.next=head
        return temp
    }
    let curr=head
    for( let i=0; i<pos-2 && curr!==null; i++){
        curr=curr.next;
    }
    if(curr===null) return head
    temp.next=curr.next
    curr.next=temp;
    return head;

}

//Delete the first node in singly linked list
function deleteHead(head){
    // let temp= head.next
    //delete head // no need, memory is managed automatically via garbage collection

    return head.next
}

//delete the last node of singly linked list
 function deleteLast(head){
    if(head===null || head.next===null) return null
    let curr = head;
    if(curr.next.next!==null){
        curr=curr.next // 10 20 30 40 null
    }
    curr.next=null // 10 20 30 null
    return head
 }

// Create initial list: 10 → 20 → 30
let head = new Node(10);
head.next = new Node(20);
head.next.next = new Node(30);

// Insert 5 at the beginning
// head = insertAtBeg(head, 5);

// head= insertAtEnd(head, 40)

// head= insertAtGvnPos(head,2, 37)

// head= deleteHead(head)
// head= deleteHead(head)

head= deleteLast(head)
head= deleteLast(head)
traverse(head);
