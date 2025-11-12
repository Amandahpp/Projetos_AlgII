create table categorias(
codigo_livro integer not null,
descricao text not null,
primary key (codigo_livro)
);
INSERT INTO categorias  VALUES
(1,'Ficcao Cientifica'),
(2,'Romance'),
(3,'Historia');
select * from categorias;
SELECT * FROM categorias ORDER BY descricao;
SELECT * FROM categorias WHERE codigo_livro > 1;

create table autores(
cpf char(11) not null,
nome text not null,
telefone char(10) not null,
endereco text not null,
primary key(cpf)
);
INSERT INTO autores VALUES
('11111111111', 'Isaac Asimov', '1199999999', 'Nova York'),
('22222222222', 'Machado de Assis', '2188888888', 'Rio de Janeiro');
SELECT * FROM autores;
SELECT nome FROM autores WHERE cpf = '11111111111';
SELECT cpf, nome FROM autores ORDER BY nome;

create table editoras(
genero integer not null,
nome text not null,
primary key(genero)
);
INSERT INTO editoras  VALUES
(1,'Editora Alpha'),
(2,'Editora Beta');
SELECT * FROM editoras;
SELECT nome FROM editoras WHERE genero = 1;
SELECT genero, nome FROM editoras ORDER BY nome;
SELECT genero FROM editoras WHERE nome = 'Editora Beta';

create table livros(
codigo_livro integer not null,
genero integer not null,
nome text not null,
editora integer not null,
categoria integer not null,
primary key (codigo_livro),
foreign key (editora) references editoras (genero),
foreign key (categoria) references categorias (codigo_livro)
);
INSERT INTO livros  VALUES
(1, 1, 'Fundação', 1, 1),
(2, 2, 'Dom Casmurro', 2, 2);
SELECT * FROM livros;
SELECT nome FROM livros WHERE codigo_livro = 1;
SELECT codigo_livro, nome FROM livros ORDER BY categoria;
SELECT nome FROM livros WHERE editora = 2;

create table bibliotecarias(
cpf char(11) not null,
nome text not null,
telefone char(11) not null,
efetiva char(1) not null check (efetiva in ('S', 'N')),
primary key (cpf)
);
INSERT INTO bibliotecarias VALUES
('55555555555','amanda', '54555555555', 'S');
select * from bibliotecarias;
SELECT * FROM bibliotecarias WHERE efetiva = 'S';
SELECT * FROM bibliotecarias ORDER BY nome;

create table estantes(
categoria integer not null,
codigo_livro integer not null,
localizacao text not null,
primary key (codigo_livro)
);
INSERT INTO estantes VALUES
(1,1, 'Corredor A - Prateleira 1'),  
(2,2, 'Corredor B - Prateleira 2');
SELECT * FROM estantes;
SELECT localizacao FROM estantes WHERE codigo_livro = 1;
SELECT codigo_livro, localizacao FROM estantes ORDER BY localizacao;
SELECT codigo_livro FROM estantes WHERE localizacao = 'Corredor B - Prateleira 2';

create table organizacao(
cod_organizacao integer not null,
bibliotecaria char (11) not null,
funcionarios integer not null,
estante integer not null,
primary key(cod_organizacao),
foreign key (bibliotecaria) references bibliotecarias (cpf),
foreign key (estante) references estantes (codigo_livro)
);
INSERT INTO organizacao VALUES
(1, '55555555555', 2, 1),
(2, '55555555555', 1, 2);
SELECT * FROM organizacao;
SELECT * FROM organizacao WHERE estante = 1;
SELECT * FROM organizacao ORDER BY cod_organizacao;

create table exemplares(
livro integer not null,
genero integer not null,
codigo_livro integer not null,
estante integer not null,
primary key (codigo_livro),
foreign key (livro) references livros(codigo_livro),
foreign key(estante) references estantes (codigo_livro)
);
INSERT INTO exemplares VALUES
(1,1,1,1),
(2,2,2,2);
SELECT * FROM exemplares;
SELECT * FROM exemplares WHERE livro = 1;
SELECT * FROM exemplares WHERE estante = 2;

create table pessoas(
nome text not null,
cpf char(11) not null,
telefone char(11) not null,
tipo char(1) not null check (tipo in ('B', 'U')),
primary key (cpf)
);
INSERT INTO pessoas VALUES
('44444444444', 'Ana Silva', '11911112222', 'U'),
('55555555555', 'Bruno Costa', '11933334444', 'U');
select * from pessoas;
SELECT * FROM pessoas WHERE tipo = 'U';
SELECT * FROM pessoas ORDER BY nome;

create table livros_autores(
livro integer not null,
autor char(11) not null,
primary key(livro, autor),
foreign key(livro) references livros (codigo),
foreign key(autor) references autores (cpf)
); 



create table reservas(
pessoa integer not null,
bibliotecaria integer not null,
data date not null,
codigo_livro integer not null,
primary key (codigo_livro),
foreign key (pessoa) references pessoas (cpf),
foreign key (bibliotecaria) references bibliotecarias (cpf)
);
INSERT INTO reservas (cpf_pessoa, cpf_bibliotecaria, codigo_livro, data) VALUES
('55555555555', '55555555555', 3, '2025-11-05');
select * from reservas;
SELECT * FROM reservas WHERE data = '2025-11-05';
SELECT * FROM reservas ORDER BY data;

create table emprestimos(
codigo_livro integer not null, 
data_saida date not null, 
data_entrega date not null,
custo numeric(10,2) not null,
exemplar integer not null,
bibliotecaria integer not null,
pessoa integer not null,
primary key (codigo_livro),
foreign key (exemplar) references exemplares (codigo_livro),
foreign key (bibliotecaria) references bibliotecarias (cpf),
foreign key (pessoa) references pessoas (cpf)
);
INSERT INTO emprestimos VALUES
(1, '44444444444', '55555555555', '2025-11-01', '2025-11-08', 5.00),
(2, '55555555555', '55555555555', '2025-11-02', '2025-03-04', 5.00);
select * from emprestimos;
SELECT * FROM emprestimos WHERE custo > 4;
SELECT * FROM emprestimos ORDER BY data_saida;

create table pedidos(
editora integer not null,
bibliotecaria integer not null,
codigo_livro integer not null ,
quantidade_pedidos integer not null,
primary key (codigo_livro),
foreign key (bibliotecaria) references bibliotecarias (cpf),
foreign key (editora) references editoras (genero)
);
INSERT INTO pedidos VALUES
(1, '55555555555', 1, 10),
(3, '55555555555', 3, 5);
select * from pedidos;
SELECT * FROM pedidos WHERE quantidade_pedidos > 5;
SELECT * FROM pedidos ORDER BY codigo_livro;




















