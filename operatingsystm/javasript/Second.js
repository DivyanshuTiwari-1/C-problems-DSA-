// *****DOM 
/**
 * 
 * 
 *   
element accessing method in js 
document.getElementById("myid")

//  */
// document.body.style.background="pink";
// /7777777777777777777
// let div=document.querySelector("div");
// console.log(div);

// div.getAttribute("id");
//     // how to  insert the new thing in the js
//     // firstly creates it than add
//     let newbtn=document.createElement("button");
//     newbtn.innerText="clickme"  ;
//     console.log(newbtn);
//     /*
    // let el=document.createELement("div") 
    // node.append(el)// adds at the end of node (inside)
    // node.prepand(el)// adds at the start of the node (inside)
    // node.before(el)// adds before the node (outside)
    // node.after(el)// adds after the node(outside)

    


    //  */
    // let div1=document.querySelector("div");
    // div1.append(newbtn);
    /**
     *  evants 
     * 
the change is state of an object is a evant

node.event;
node.addEventListenser(event,callback)
node.removeEventListenser(event,callback)
*/
let btt=document.querySelector("#bt1");
 let a="kala";
btt.addEventListener("click",()=>{
    if(a==="kala"){
        a="safed";
       
        document.querySelector("body").style.background="black";
    }
 else {
    a="kala";
    document.querySelector("body").style.background="white";

 }




});








    