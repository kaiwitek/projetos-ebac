const form = document.getElementById('formctt')
const nome = []
const number = []
let linhas = ''

form.addEventListener('submit', function(e) {
    e.preventDefault()

    adicionaLinha()
    atualizaTabela()
})

function adicionaLinha() {
    const inputNome = document.getElementById('nomectt')
    const inputNumero = document.getElementById('telctt')

    if (nome.includes(inputNome.value)) {
        alert(`O contato "${inputNome.value}" já existe`)
    }

    else {
        nome.push(inputNome.value)
        number.push(inputNumero.value)

        let linha = '<tr>'
        linha += `<td>${inputNome.value}</td>`
        linha += `<td>${inputNumero.value}</td>`
        linha += '</tr>'

        linhas += linha
    }

    inputNome.value = ''
    inputNumero.value = ''
}

function atualizaTabela() {
    const corpoTabela = document.getElementById('corpotabela')

    corpoTabela.innerHTML = linhas
}