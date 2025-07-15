class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

// traverse a circular linked list
function traverse(head) {
    if (head === null) return;          // empty list

    let curr = head;
    do {
        console.log(curr.data);
        curr = curr.next;
    } while (curr !== head);
}

// insert at beginning (tail pointer trick)
function insertAtBegin(head, x) {
    const temp = new Node(x);

    // empty list: new node points to itself and is now the only/tail node
    if (head === null) {
        temp.next = temp;
        return temp;
    }

    // insert temp right after the tail node (head)
    temp.next = head.next;
    head.next = temp;

    // swap data between head (tail) and new node so x appears first
    [temp.data, head.data] = [head.data, temp.data];

    return head;        // tail pointer (unchanged)
}

/* ---------- demo ---------- */
let head  = new Node(10);
let n20   = new Node(20);
let n30   = new Node(30);
let n35   = new Node(35);
let n40   = new Node(40);

head.next = n20;
n20.next  = n30;
n30.next  = n35;
n35.next  = n40;
n40.next  = head;   // make it circular (head is the *tail* pointer)

/* insert 4 at logical beginning */
head = insertAtBegin(head, 4);

/* show the list */
traverse(head);
// → 4 10 20 30 35 40
