class MyStack{
    constructor(){
        this.arr=[]
    }

    push(x){
        this.arr.push(x);
    }
    pop(){
        if(this.isEmpty()){
            throw new Error("underflow")
        }
        return this.arr.pop();
    }
    size(){
        return this.arr.length;
    }
    isEmpty(){
        return this.arr.length===0
    }
    peek(){
        if(this.isEmpty()){
            throw new Error('Stack is empty')
        }
        return this.arr[this.arr.length-1]
    }
}

//linked List implementation
class Node{
    constructor(data){
        this.data=data
        this.next=null
    }
}

class MyStack{
    constructor(){
        this.head=null
        this.sz=0
    }
    push(x){
        const temp= new Node(x)
        temp.next=this.head;
        this.head=temp
        this.sz++;
    }
    pop(){
        if(this.head===null){
            throw new Error("Stack underflow")
        }
        const res=this.head.data;
        this.head=this.head.next
        this.sz--;
        return res;
    }
    peek(){
        if(this.head===null){
            throw new Error("Stack underflow")
        }
        return this.head.data
    }
    size(){
        return this.sz;
    }

    isEmpty(){
        return this.sz===0
    }
}

const s= new MyStack()
s.push(10);
s.push(20);
console.log(s.peek());   
console.log(s.pop());   
console.log(s.size());   
console.log(s.isEmpty());