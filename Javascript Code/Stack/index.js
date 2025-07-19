// class Stack {
//     constructor() {
//         this.items = [];
//     }

//     push(x) {
//         this.items.push(x);
//     }

//     pop() {
//         return this.items.pop();
//     }

//     top() {
//         return this.items[this.items.length - 1];
//     }

//     isEmpty() {
//         return this.items.length === 0;
//     }
// }

// // Main logic
// const st = new Stack();
// st.push(10);
// st.push(30);
// st.push(35);
// st.push(40);

// while (!st.isEmpty()) {
//     console.log(st.top() + " ");
//     st.pop();
// }


// const s=[]
// s.push(10)
// s.push(20)
// s.push(30)


// while(s.length !== 0){
//     console.log(s.pop());
// }

// class Stack extends Array{
//     top(){
//         return this[this.length-1]
//     }
//     isEmpty(){
//         return this.length===0
//     }
// }

// const st= new Stack()
// st.push(10);
// st.push(30);
// st.push(35);
// st.push(40);
// while (!st.isEmpty())
// {
//     console.log(st.top()+" ");
    
//     st.pop();
// }

//balanced parenthesis
class Stack extends Array{
    top(){
        return this[this.length-1]
    }
    empty(){
        return this.length===0
    }
}

function match(a, b){
    return ((a==='(' && b===')') || (a==='[' && b===']') || (a==='{' && b==='}'))
}

function balanced(str){
    const s=new Stack();
    for (const x of str) {
        if(x==='(' ||  x==='[' || x==='{' ){
            s.push(x)
        }else{
            if(s.empty() || !match(s.top(), x)){
                return false;
            }else{
                s.pop();
            }
        }
    }
    return s.empty();


}
console.log(balanced("(())"));        // true
console.log(balanced("({[]})"));      // true
console.log(balanced("([)]"));        // false
console.log(balanced("("));           // false
console.log(balanced(""));            // true
console.log(balanced("{[()]()}"));    // true
