const form = document.getElementById('formatv')
const imgAprovado = '<img src="imagens/aprovado.png" alt="emoji comemorando" />'
const imgReprovado = '<img src="imagens/reprovado.png" alt="emoji decepcionado" />'
const atividades = []
const notas = []
const spanAprovado = '<span class="resultado aprovado">Aprovado</span>'
const spanReprovado = '<span class="resultado reprovado">Reprovado</span>'
const notaMinima = parseFloat(prompt('Digite a nota mínima:'))

let linhas = ''

form.addEventListener('submit', function(e) {
    e.preventDefault()

    adicionaLinha()
    atualizaTabela()
    calculaMediaFinal()
    atualizaMediaFinal()
})

function adicionaLinha() {
    const inputNomeAtividade =  document.getElementById('nomeatv')
    const inputNota = document.getElementById('nota')

    if (atividades.includes(inputNomeAtividade.value)) {
        alert(`A atividade "${inputNomeAtividade.value}" já foi inserida!`)
    }

    else {
        atividades.push(inputNomeAtividade.value)
        notas.push(parseFloat(inputNota.value))
    
    
        let linha = '<tr>'
        linha += `<td>${inputNomeAtividade.value}</td>`
        linha += `<td>${inputNota.value}</td>`
        linha += `<td>${inputNota.value >= notaMinima ? imgAprovado : imgReprovado}</td>`
        linha += `</tr>` 
    
        linhas += linha
    
    }


    inputNomeAtividade.value = ''
    inputNota.value = ''
}

function atualizaTabela() {
    const corpoTabela = document.querySelector('tbody')

    corpoTabela.innerHTML = linhas
}

function calculaMediaFinal() {
    let somaNotas = 0;

    for (let i = 0; i < notas.length; i++) {
        somaNotas += notas[i];
    }

    const media = somaNotas / notas.length

    return media
}

function atualizaMediaFinal() {
    const mediaFinal = calculaMediaFinal()

    document.getElementById('mfv').innerHTML = mediaFinal.toFixed(1)
    document.getElementById('mfr').innerHTML = mediaFinal >= notaMinima ? spanAprovado : spanReprovado
}