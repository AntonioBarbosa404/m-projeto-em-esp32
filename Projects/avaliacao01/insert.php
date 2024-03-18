<?php

// Recebe o estado do botão via GET
$estado = $_GET['estado'];

// Conecta ao banco de dados
$db = new SQLite3('unidades.db');

// Cria a query SQL
$query = "INSERT INTO setor (situacao, data_hora) VALUES ('$estado', datetime('now'))";

// Executa a query
$db->exec($query);

// Fecha a conexão com o banco de dados
$db->close();

echo "Dados recebidos e armazenados no banco de dados!";

?>
