let userscore=0;
let compscore=0;


const choices=document.querySelectorAll(".choice");
let msg=document.querySelector("#btn");
let userCount=document.querySelector("#user-score");
let compCount=document.querySelector("#comp-score");

const genCompChoice=()=>{
  const options=["rock","paper","scissors"];
 const randInd= Math.floor(Math.random()*3);
  return options[randInd];
}
https://github.com/DiyanshuTiwaari/tice-tace-toe.git
const drawgame=(compChoice)=>{
  console.log("game drawn");
  msg.innerText=` Game drawn! as computer choice is ${ compChoice}`;
  msg.style.backgroundColor="blue";

};
const showWinner=(userWin ,userChoice,compChoice)=>{
  if(userWin){
    console.log("you win");
     userscore++;
     userCount.innerText= userscore;
     msg.innerText=`you win! ${userChoice} beats ${ compChoice} as computer choice is ${ compChoice} `;
     msg.style.backgroundColor="green";
  }
  else{
    console.log("you lose");
    compscore++;
    compCount.innerText=compscore;
    msg.innerText=`you loss! ${compChoice} beats ${ userChoice} as computer choice is ${ compChoice} `;
    msg.style.backgroundColor="red";

  }
}

const playGame=(userChoice)=>{
  console.log("user choice=",userChoice);
  const compChoice=genCompChoice();
  console.log("computer choice=",compChoice);
   if( userChoice === compChoice){
    //draw game
    drawgame(compChoice);
   }
   else{
       let userWin=true;
       if (userChoice=== "rock"){
        // paper,scissors
        userWin=compChoice==="paper"? false:true;
       }
       else if( userChoice==="paper"){
        // rock ,scissors
        userWin=compscore==="scissors" ? false:true;
       }
       else{
        // paper,rock
        userWin=compChoice==="paper"? true:false;
       }
       showWinner(userWin,userChoice,compChoice);
   }

};







choices.forEach((choice)=>{
  choice.addEventListener("click",()=>{
     const userChoice=choice.getAttribute("id");
    playGame(userChoice);
  });
});