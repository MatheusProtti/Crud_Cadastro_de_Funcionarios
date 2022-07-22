const modalContainer = document.querySelector('.modal-container');
const tbody = document.querySelector('tbody');
const modalName = document.querySelector('#modalName');
const modalFunction = document.querySelector('#modalFunction');
const modalWage = document.querySelector('#modalWage');
const btnSave = document.querySelector('#btnSave');
const btnNew = document.querySelector('#new');

let itens; //criando a variavel que ira ser o array.
let id; // criando os id.

// # Aqui é o banco de dados local usando o localStorage.
const getItensBD = () => JSON.parse(localStorage.getItem('db_client')) ?? []
const setItensBD = () => localStorage.setItem('db_client', JSON.stringify(itens))

// # Carrega os itens.
function loadItens() {
    
    itens = getItensBD()
    tbody.innerHTML = ''
    itens.forEach((item, index) => {
      insertDataIntoTheTable(item, index)
    })
}

loadItens()

// # Insere os dados na tabela pelo js.
function insertDataIntoTheTable(item, index){
    let tr = document.createElement('tr');
    
    tr.innerHTML = `
        <td>${item.nome}</td>
        <td>${item.funcao}</td>
        <td>R$ ${item.salario}</td>
        <td>
            <button onclick="editItem(${index})"><img class="editimg" src="./img/edit-img.png"></button>
        </td>
        <td>
            <button onclick="deleteItem(${index})"><img class="edittrash" src="./img/icons8-trash-24.png"></button>
        </td>`
                    
    tbody.appendChild(tr)
}

// # Usando o argumneto edit no openCloseModal permite com que alterando para true abra o modal de novo e eu possa alterar ele.
function editItem(index){

    openCloseModal(true, index)
}

// # Aqui deletamos os itens da lista usando o slice, removendo os elementos do array.
function deleteItem(index){
    itens.splice(index, 1)
    setItensBD()
    loadItens()
}

// # Aqui eu abro e fecho o modal-container, adicionando e tirando a class active.
function openCloseModal(edit = false, index = 0){
    modalContainer.classList.add('active');

    modalContainer.onclick = e => {
        if (e.target.className.indexOf('modal-container') !== -1) {
          modalContainer.classList.remove('active')
        }
    }
    
    // # Se cair no edit abrira com os dados que ja tem nele.
    if (edit) {
        modalName.value = itens[index].nome;
        modalFunction.value = itens[index].funcao;
        modalWage.value = itens[index].salario;
        id = index;
    } else { //# Se não ira abrir o modal vazio para adiconar um novo 'cadastro'.
        modalName.value = '';
        modalFunction.value = '';
        modalWage.value = '';
    }
    
}

// # Onde se salva os dados para ir para a tabela.
btnSave.onclick = e =>{

    // # Se algum campo estiver vazio cai nesse if e nao deixa continuar.
    if (modalName.value == '' || modalFunction.value == '' || modalWage.value == '') {

        return console.log('espaço em branco')
    } 

    e.preventDefault();

    if (id !== undefined) {
        itens[id].nome = modalName.value
        itens[id].funcao = modalFunction.value
        itens[id].salario = modalWage.value
    } else { // Verifica se o itens é array mesmo.
        // if(Array.isArray(arr)){ 
        //     itens.push({'nome': modalName.value, 'funcao': modalFunction.value, 'salario': modalWage.value})
        // }
        itens.push({'nome': modalName.value, 'funcao': modalFunction.value, 'salario': modalWage.value}) 
        //dessa maneira não ocorre a verificação.
    }
    
    setItensBD()
    
    modalContainer.classList.remove('active')
    loadItens()
    id = undefined
}
