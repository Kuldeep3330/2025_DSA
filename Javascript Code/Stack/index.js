class Stack extends Array{
    top(){
        return this[this.length-1]
    }
    isEmpty(){
        return this.length===0
    }
}

