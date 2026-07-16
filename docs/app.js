const $=(s,p=document)=>p.querySelector(s),$$=(s,p=document)=>[...p.querySelectorAll(s)];
const questions=[
 {category:'Programming',q:'Which of the following is NOT a valid programming paradigm?',o:['Procedural','Functional','Logical','Iterative'],a:3},
 {category:'Algorithms',q:'Which sorting algorithm has a worst-case time complexity of O(n²)?',o:['Merge Sort','Quick Sort','Heap Sort','Insertion Sort'],a:3},
 {category:'Databases',q:'What is the purpose of the SQL language?',o:['Storing and retrieving data from a relational database','Writing server-side scripts for web applications','Creating interactive user interfaces','Defining the structure of HTML documents'],a:0},
 {category:'Web',q:'Which of the following is NOT a valid HTTP request method?',o:['GET','POST','PUSH','DELETE'],a:2},
 {category:'Data structures',q:'Which data structure is typically used to implement FIFO (First In, First Out) behaviour?',o:['Stack','Queue','Heap','Linked List'],a:1},
 {category:'Machine learning',q:'Which of the following is NOT a recognised machine-learning approach?',o:['Supervised Learning','Unsupervised Learning','Reinforcement Learning','Interactive Learning'],a:3},
 {category:'Object-oriented programming',q:'What is the purpose of a constructor in object-oriented programming?',o:['To destroy objects after they are no longer needed','To initialise the state of an object when it is created','To define private methods within a class','To implement inheritance between classes'],a:1},
 {category:'Web',q:'Which of the following is NOT a valid HTTP status code?',o:['200','404','503','1000'],a:3},
 {category:'Programming',q:'What is the role of a compiler in software development?',o:['To translate high-level code into machine code','To debug errors in source code','To manage version control','To optimise database queries'],a:0},
 {category:'Object-oriented programming',q:'Inheritance allows a class to inherit properties and methods from another class.',o:['True','False'],a:0},
 {category:'Algorithms',q:'Dynamic programming solves problems by breaking them into subproblems and solving each subproblem only once.',o:['True','False'],a:0},
 {category:'Networking',q:'IPv6 addresses are shorter than IPv4 addresses.',o:['True','False'],a:1},
 {category:'Data structures',q:'A binary search tree guarantees constant-time lookup for every element.',o:['True','False'],a:1},
 {category:'Web',q:'HTML is a programming language used for creating web pages.',o:['True','False'],a:1},
 {category:'Machine learning',q:'Machine-learning algorithms can learn from data without being explicitly programmed for every outcome.',o:['True','False'],a:0},
 {category:'Algorithms',q:'Big O notation can describe the worst-case growth of an algorithm.',o:['True','False'],a:0},
 {category:'Security',q:'HTTPS provides encrypted communication over a computer network.',o:['True','False'],a:0},
 {category:'Software development',q:'Agile software development prioritises extensive documentation and comprehensive plans over working software.',o:['True','False'],a:1},
 {category:'Programming',q:'Python is always compiled directly into native machine code before it runs.',o:['True','False'],a:1}
];
const userKey='quizAppUsersV2',demoHash='d3ad9315b7be5dd53b31a273b3b3aba5defe700808305aa16a3062b76658a791';
let users=JSON.parse(localStorage.getItem(userKey)||'null')||[{username:'portfolio',hash:demoHash}],currentUser='',level='',round=[],answers=[],index=0,secondsLeft=0,timerId=null;
const show=id=>{$$('.screen').forEach(s=>s.classList.toggle('active',s.id===id))};
const hash=async value=>{const buf=await crypto.subtle.digest('SHA-256',new TextEncoder().encode(value));return[...new Uint8Array(buf)].map(b=>b.toString(16).padStart(2,'0')).join('')};

$$('[data-auth-view]').forEach(b=>b.onclick=()=>{const login=b.dataset.authView==='login';$('#loginForm').hidden=!login;$('#registerForm').hidden=login});
$('#guestLogin').onclick=()=>enterDashboard('Portfolio Guest');
$('#loginForm').onsubmit=async e=>{e.preventDefault();const f=e.currentTarget,u=users.find(x=>x.username.toLowerCase()===f.username.value.trim().toLowerCase()),h=await hash(f.password.value);if(!u||u.hash!==h){$('.message',f).textContent='Username or password is incorrect.';return}enterDashboard(u.username)};
$('#registerForm').onsubmit=async e=>{e.preventDefault();const f=e.currentTarget,name=f.username.value.trim(),msg=$('.message',f);if(f.password.value!==f.confirm.value){msg.textContent='Passwords do not match.';return}if(users.some(u=>u.username.toLowerCase()===name.toLowerCase())){msg.textContent='That username already exists.';return}users.push({username:name,hash:await hash(f.password.value)});localStorage.setItem(userKey,JSON.stringify(users));enterDashboard(name)};
function enterDashboard(name){currentUser=name;$('#dashUser').textContent=`Signed in as ${name}`;show('dashboard')}
$('#logout').onclick=()=>{currentUser='';show('auth')};
$$('[data-level]').forEach(b=>b.onclick=()=>startQuiz(b.dataset.level));
function shuffle(list){const a=[...list];for(let i=a.length-1;i>0;i--){const j=Math.floor(Math.random()*(i+1));[a[i],a[j]]=[a[j],a[i]]}return a}
function startQuiz(selectedLevel){level=selectedLevel;round=shuffle(questions).slice(0,8);answers=Array(8).fill(null);index=0;clearInterval(timerId);secondsLeft=level==='medium'?1800:level==='hard'?30:0;$('#timerWrap').hidden=level==='easy';$('#previous').hidden=level!=='easy';show('quiz');if(secondsLeft){renderTimer();timerId=setInterval(()=>{secondsLeft--;renderTimer();if(secondsLeft<=0){clearInterval(timerId);finishQuiz(true)}},1000)}renderQuestion()}
function renderQuestion(){const item=round[index];$('#progressLabel').textContent=`Question ${index+1} of ${round.length}`;$('#progressBar').style.width=`${(index+1)/round.length*100}%`;$('#levelLabel').textContent=`${level.toUpperCase()} · ${item.category.toUpperCase()}`;$('#questionNumber').textContent=String(index+1).padStart(2,'0');$('#questionText').textContent=item.q;$('#answerForm').innerHTML=item.o.map((o,i)=>`<label class="answer"><input type="radio" name="answer" value="${i}" ${answers[index]===i?'checked':''}><i>${String.fromCharCode(65+i)}</i><span>${o}</span></label>`).join('');$('#previous').disabled=index===0;$('#next').textContent=index===round.length-1?'Finish quiz →':'Next question →';$('#answerWarning').textContent=''}
function saveCurrent(){const checked=$('#answerForm input:checked');if(!checked)return false;answers[index]=+checked.value;return true}
$('#next').onclick=()=>{if(!saveCurrent()){$('#answerWarning').textContent='Please select an answer before proceeding.';return}if(index<round.length-1){index++;renderQuestion()}else finishQuiz(false)};
$('#previous').onclick=()=>{const checked=$('#answerForm input:checked');if(checked)answers[index]=+checked.value;if(index>0){index--;renderQuestion()}};
$('#clearChoice').onclick=()=>{$$('#answerForm input').forEach(x=>x.checked=false);answers[index]=null;$('#answerWarning').textContent=''};
$('#exitQuiz').onclick=()=>{if(confirm('Exit this quiz? Your current answers will be lost.')){clearInterval(timerId);show('dashboard')}};
function renderTimer(){const m=Math.floor(secondsLeft/60),s=secondsLeft%60;$('#timer').textContent=`${String(m).padStart(2,'0')}:${String(s).padStart(2,'0')}`;$('#timerWrap').classList.toggle('danger',secondsLeft<=10)}
function finishQuiz(timedOut){clearInterval(timerId);const score=round.reduce((sum,q,i)=>sum+(answers[i]===q.a?1:0),0),percent=Math.round(score/round.length*100);$('#score').textContent=`${score}/${round.length}`;$('#percent').textContent=`${percent}%`;$('#resultHeading').textContent=timedOut?'Time is up.':'Quiz complete.';$('#resultMessage').textContent=percent>=88?'Excellent result.':percent>=63?'Good foundation.':percent>=38?'Keep building your knowledge.':'Review and try again.';$('#resultDetail').textContent=`You completed the ${level} difficulty with ${score} correct answer${score===1?'':'s'} out of ${round.length}.${timedOut?' The timer ended the quiz automatically.':''}`;$('#reviewList').innerHTML=round.map((q,i)=>{const correct=answers[i]===q.a;return `<article class="review-item"><span class="review-mark ${correct?'':'wrong'}">${correct?'✓':'×'}</span><div><h3>${i+1}. ${q.q}</h3><p>Your answer: ${answers[i]===null?'Not answered':q.o[answers[i]]}</p>${!correct?`<p>Correct answer: <b>${q.o[q.a]}</b></p>`:''}</div></article>`}).join('');show('results')}
$('#backDashboard').onclick=()=>show('dashboard');$('#toggleReview').onclick=e=>{const hidden=$('#reviewList').hidden=!$('#reviewList').hidden;e.target.textContent=hidden?'Show review':'Hide review'};
