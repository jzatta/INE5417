CREATE TABLE `file` (
  `name` VARCHAR(40) NOT NULL,
  `counter` INTEGER NOT NULL,
  PRIMARY KEY (`name`)
);

CREATE TABLE `username` (
  `name` VARCHAR(40) NOT NULL,
  `password` VARCHAR(40) NOT NULL,
  `authority` VARCHAR(6) NOT NULL, -- su or common
  PRIMARY KEY (`name`)
);

CREATE TABLE `logname` (
  `codigo` INTEGER NOT NULL,
  `change` VARCHAR(40) NOT NULL,
  `owner` VARCHAR(40) NOT NULL,
  `data` integer NOT NULL,
  `sequence` INTEGER NOT NULL,
  `name` VARCHAR(40) NOT NULL,
  PRIMARY KEY (`codigo`),
  FOREIGN KEY (`name`) REFERENCES `file`(`name`)
);