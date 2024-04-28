const list = document.querySelectorAll('[aria-label="Menu de ações"]');

function openmenu (list, i) {    
list[i].click();
}
function salvar () {
document.querySelectorAll('[role="option"]')[2].click();
}
function selecionar () {  
document.querySelector('[title="/mu/teste"]').click();
}
function cancelar () {
document.querySelector('[aria-label="Cancelar"]').click();
}

let i = 1;
setInterval(()=> {
i++;
console.log("iteracao numero "+i);
	if (i == list.length) {
		console.log("parei");
		clearInterval();
	}
	setTimeout( ()=> {	
		openmenu(list,i); 
		setTimeout ( ()=> {
			salvar();
			setTimeout( ()=> {
				selecionar();
				cancelar();					
			}, 1000);
		}, 1000);
	    }, 1000);	
}, 2000);

clearTimeout();

let total = 0;
let target = 50;
const clickAll = () =&gt; {
  let count = 0;
  let btns = document.querySelectorAll('.search-result__actions .search-result__actions--primary');
  btns.forEach((btn) =&gt; {
    count ++;
    total ++;
    setTimeout(() =&gt; {
      btn.click();
      setTimeout(() =&gt; {
        let confirmations = document.querySelectorAll('.artdeco-modal__actionbar .artdeco-button--primary');
        confirmations.forEach((cBtn) =&gt; { cBtn.click() });
      },3000);
    }, count * 30000);
  });
  if (total &lt; target) {
    setTimeout(() =&gt; {
      let nextBtns = document.querySelectorAll('.artdeco-pagination__button--next');
      nextBtns.forEach((nBtn) =&gt; { nBtn.click() });
    }, (count + 1) * 30000);
    setTimeout(() =&gt; {
      clickAll();
    }, (count + 2) * 30000);
  }
}
clickAll();