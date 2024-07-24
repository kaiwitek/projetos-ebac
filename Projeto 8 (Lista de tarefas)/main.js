$(document).ready(function(){

        $('.nova-tarefa').click(function(){
            $('form').slideDown()
        })

        $('#cancelar').click(function(){
            $('form').slideUp()
        })

        $('form').on('submit', function(e) {
            e.preventDefault()
            const nomeDaTarefa = $('#adicionar-tarefa').val()
            const novaTarefa = $(`<li>${nomeDaTarefa}</li>`)
            const semTarefa = $('p')
            $(novaTarefa).appendTo('ul')
            $(semTarefa).remove()
            $('#adicionar-tarefa').val('')
        })

        $('ul').on('click', 'li', function(){  
            $(this).toggleClass('completada')
        });

})