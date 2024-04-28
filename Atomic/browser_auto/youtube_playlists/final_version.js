const list = document.querySelectorAll('[aria-label="Menu de ações"]');

function openmenu (list, i) {    
    list[i].click();
}
function salvar () {
    document.querySelectorAll('[role="option"]')[2].click();
}
function selecionar () {  
    document.querySelector('[title="/mu/teste"]').click(); //alterar aqui titulo da playlist
}
function cancelar () {
    document.querySelector('[aria-label="Cancelar"]').click();
}

let i = -1;
let iteracoes = setInterval(()=> {
    i++;
    console.log("iteracao numero "+i);
    if (i == list.length) {
    console.log("finalizando...");
    clearInterval(iteracoes);
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
