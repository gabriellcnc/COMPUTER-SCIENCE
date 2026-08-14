-- Estudo de Caso Escola
-- Modelo/Projeto físico
-- Linguagem SQL

CREATE TABLE Cidade(
	codigo	INT			PRIMARY KEY,
	nome	VARCHAR(30) NOT NULL,
	UF		CHAR(2)		DEFAULT 'RS',
	numHabitantes INT
);

	SELECT * FROM Cidade

CREATE TABLE Aluno(
	matricula INT		    NOT NULL,
	nome	  VARCHAR(40)	NOT NULL,
	dataNasc  DATE			CHECK(dataNasc <= current_date),
	codCidade INT,
	FOREIGN KEY(codCidade)	REFERENCES Cidade(codigo)
);

	SELECT * FROM Aluno

-- DROP TABLE aluno;
-- DROP TABLE cidade;

--	ALTER TABLE Aluno ADD constraint pk_aluno PRIMARY KEY(matricula);

--	ALTER TABLE Cidade rename numGabitantes to numHabitantes

--	ALTER TABLE Aluno rename datanasc to dataNasc



-------------------------------------------------------------------------------------

	-- CARGA DE DADOS --

	SELECT * FROM Cidade

INSERT INTO Cidade(codigo,nome,uf,numHabitantes) VALUES(1,'Passo Fundo','RS',215081);

INSERT INTO Cidade(codigo,nome,uf,numHabitantes) VALUES(2,'União da Serra','RS',1170);

INSERT INTO Cidade(codigo,nome,uf,numHabitantes) VALUES(3,'Chapeco','SC',27001);

INSERT INTO Cidade(codigo,nome,uf,numHabitantes) VALUES(4,'Não me Toque','RS',21000);

INSERT INTO Cidade(codigo,nome,uf,numHabitantes) VALUES(5,'São Paulo','Sp',11904961);

INSERT INTO Cidade(codigo,nome,uf,numHabitantes) VALUES(6,'Tunas','RS',3000);

INSERT INTO Cidade(codigo,nome,uf,numHabitantes) VALUES(7,'Lagoa Vermelha','RS',27001);

INSERT INTO Cidade(codigo,nome,uf,numHabitantes) VALUES(8, 'Guaporé','RS',25268);

INSERT INTO Cidade(codigo,nome,uf,numHabitantes) VALUES(9,'Serrafina Correa', 'RS', 16191 );

INSERT INTO Cidade(codigo,nome,uf,numHabitantes) VALUES(10,'Gramado','RS',40134);

INSERT INTO Cidade(codigo,nome) VALUES(11,'Casca');

UPDATE Cidade SET numHabitantes = 9460 WHERE codigo = 11; -- ou nome = 'Casca'

-----------------------------------------------------------------------------------------------

SELECT * FROM Aluno

INSERT INTO Aluno(matricula,nome,datanasc,codcidade)	VALUES(214143,'Gabriel Cenci','06/06/2007',2);

INSERT INTO Aluno(matricula,nome,datanasc,codcidade)	VALUES(122,'Ana','10/01/2000',1);

INSERT INTO Aluno(matricula,nome,codcidade)				VALUES(123,'Juca', 1);

INSERT INTO Aluno(matricula,nome,codcidade)				VALUES(124,'Priscila', 2);

INSERT INTO Aluno(matricula,nome,datanasc,codcidade)	VALUES(125,'Cadu','20/01/2008', 6);

INSERT INTO Aluno										VALUES(126,'Juca','31/10/2007',2);

UPDATE Aluno SET nome = 'Lucas' WHERE matricula = 126;

UPDATE Aluno SET datanasc = '10/09/2007' WHERE matricula = 124;

UPDATE Aluno SET dataNasc = '01/01/1999' WHERE matricula = 123;

-----------------------------------------------------------------------------------------------------

CREATE TABLE Hobby(
	codigo		INT,
	descricao	VARCHAR(30)		NOT NULL,
	obs			VARCHAR(120),
	PRIMARY KEY(codigo)
);

	SELECT * FROM Hobby

CREATE TABLE AlunoHobby(
	matricula		INT,
	codHobby		INT,
	frequencia 		INT			NOT NULL,
	FOREIGN KEY(matricula)		REFERENCES Aluno(matricula),
	FOREIGN KEY(codHobby)		REFERENCES Hobby(codigo),
	PRIMARY KEY(matricula,codHobby)
);

	SELECT * FROM AlunoHobby

----------------------------------------------------------------------------------------------------

	SELECT * FROM Hobby

	INSERT INTO Hobby (codigo, descricao, obs) VALUES (200, 'Videogames', 'Jogos em console ou PC');
	INSERT INTO Hobby (codigo, descricao, obs) VALUES (201, 'Leitura', 'Livros de ficção e não-ficção');
	INSERT INTO Hobby (codigo, descricao, obs) VALUES (202, 'Culinária', 'Preparo de receitas doces e salgadas');
	INSERT INTO Hobby (codigo, descricao, obs) VALUES (203, 'Jardinagem', 'Cuidados com plantas e horta');
	INSERT INTO Hobby (codigo, descricao, obs) VALUES (204, 'Fotografia', 'Registros da natureza e retratos');
	INSERT INTO Hobby (codigo, descricao, obs) VALUES (205, 'Tocar Instrumento', 'Prática de violão e teclado');
	INSERT INTO Hobby (codigo, descricao, obs) VALUES (206, 'Desenho e Pintura', 'Arte digital e em tela');
	INSERT INTO Hobby (codigo, descricao, obs) VALUES (207, 'Corrida', 'Atividade física ao ar livre');
	INSERT INTO Hobby (codigo, descricao, obs) VALUES (208, 'Cinema e Séries', 'Maratonar produções e filmes');
	INSERT INTO Hobby (codigo, descricao, obs) VALUES (209, 'Xadrez', 'Jogo de estratégia e raciocínio');

-------------------------------------------------------------------------------------------------------

	SELECT * FROM AlunoHobby

	INSERT INTO AlunoHobby (matricula, codHobby, frequencia) VALUES (214143, 200, 7); 
	INSERT INTO AlunoHobby (matricula, codHobby, frequencia) VALUES (122, 201, 3);  
	INSERT INTO AlunoHobby (matricula, codHobby, frequencia) VALUES (125, 207, 5); 
	INSERT INTO AlunoHobby (matricula, codHobby, frequencia) VALUES (126, 208, 2);  
	INSERT INTO AlunoHobby (matricula, codHobby, frequencia) VALUES (124, 204, 4); 
	INSERT INTO AlunoHobby (matricula, codHobby, frequencia) VALUES (123, 209, 1);

----------------------------------------------------------------------------------------------------------

-- 1 - Listar o nome de todas cidades em ordem alfabetica

	SELECT nome
	FROM Cidade
	ORDER BY nome ASC;

-- 2 - Listar o nome e nº de habitantes com mais de 100 mil habitantes

	SELECT nome, numHabitantes
	FROM Cidade
	WHERE numHabitantes > 100000;

-- 3 - Listar o nome dos alunos que nasceram antes do ano 2000

	SELECT nome
	FROM Aluno
	WHERE dataNasc < '2000-01-01';