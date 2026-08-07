-- Estudo de Caso Escola
-- Modelo/Projeto físico
-- Linguagem SQL

CREATE TABLE Cidade(
	codigo	INT			PRIMARY KEY,
	nome	VARCHAR(30) NOT NULL,
	UF		CHAR(2)		DEFAULT 'RS',
	numGabitantes INT
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

	ALTER TABLE Aluno ADD constraint pk_aluno PRIMARY KEY(matricula);

	ALTER TABLE Cidade rename numGabitantes to numHabitantes

	ALTER TABLE Aluno rename datanasc to dataNasc



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