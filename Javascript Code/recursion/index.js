// print=(num)=>{
//     if(num==1){
//         return;
//     }
//     console.log(num); 
//     print(num-1)   
// }

// print(3)

//print 1 to N
// print=(num, N)=>{
//     if(num==N){
//         return;
//     }
//     console.log(num);
//     print(num+1, N)    
// }

// print(1, 4)

//print 1 to N
print=(num)=>{
    if(num==0){
        return;
    }
    print(num-1);
    console.log(num);    
}

print(3)