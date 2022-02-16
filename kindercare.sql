-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Feb 15, 2022 at 07:54 PM
-- Server version: 10.4.22-MariaDB
-- PHP Version: 8.0.13

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `kindercare`
--

-- --------------------------------------------------------

--
-- Table structure for table `asssignmentdetails`
--

CREATE TABLE `asssignmentdetails` (
  `assignmentId` int(3) NOT NULL,
  `assignment` varchar(10) NOT NULL,
  `expiryDate` date NOT NULL,
  `expiryTime` time NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `asssignmentdetails`
--

INSERT INTO `asssignmentdetails` (`assignmentId`, `assignment`, `expiryDate`, `expiryTime`) VALUES
(1, 'AB', '2022-02-12', '11:24:00'),
(2, 'LK', '2022-02-17', '04:52:00'),
(3, 'T', '2022-02-25', '04:55:00'),
(4, 'L', '2022-02-15', '15:49:00'),
(5, 'L', '2022-02-15', '15:49:00'),
(6, 'HTDE', '2022-02-02', '15:34:00'),
(7, 'HJTF', '2022-02-23', '21:34:00');

-- --------------------------------------------------------

--
-- Table structure for table `pupilsdetails`
--

CREATE TABLE `pupilsdetails` (
  `firstName` varchar(30) NOT NULL,
  `lastName` varchar(30) NOT NULL,
  `phoneNumber` varchar(20) NOT NULL,
  `userCode` varchar(20) NOT NULL,
  `status` varchar(30) NOT NULL DEFAULT 'Activated',
  `activationrequest` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `pupilsdetails`
--

INSERT INTO `pupilsdetails` (`firstName`, `lastName`, `phoneNumber`, `userCode`, `status`, `activationrequest`) VALUES
('Mayambala', 'Mark', '0700055576', 'KESP1', 'Deactivated', 'Requested'),
('ENOCK', 'FRED', '647474665', 'KESP10', 'Activated', ''),
('Wabwiire ', 'Edrick', '0700055533', 'KESP2', 'Activated', ''),
('Lwanga Kaye', 'Grace', '0707070709', 'KESP3', 'Activated', ''),
('Nabatanzi', 'Shifrah', '0786978543', 'KESP4', 'Activated', ''),
('Mujji', 'Geoff', '0789090945', 'KESP5', 'Activated', ''),
('Aliguma', 'Felix', '0777788856', 'KESP6', 'Activated', ''),
('Kizza', 'Herman', '0779347681', 'KESP7', 'Activated', ''),
('Magezi', 'Jeremy', '0786978543', 'KESP8', 'Deactivated', ''),
('Naigaga', 'Hasifah', '0795774849', 'KESP9', 'Activated', '');

-- --------------------------------------------------------

--
-- Table structure for table `scores`
--

CREATE TABLE `scores` (
  `assignmentId` int(6) NOT NULL,
  `userCode` varchar(15) NOT NULL,
  `marks` int(3) NOT NULL,
  `timeTaken` float NOT NULL,
  `comment` varchar(225) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `scores`
--

INSERT INTO `scores` (`assignmentId`, `userCode`, `marks`, `timeTaken`, `comment`) VALUES
(1, 'KESP1', 51, 1.2, 'work harder to improvee'),
(1, 'KESP9', 90, 2.54, 'work harder next time'),
(2, 'KESP2', 55, 1.222, 'Good'),
(2, 'KESP9', 35, 0.516667, ''),
(4, 'KESP9', 31, 0.233333, 'work harder');

-- --------------------------------------------------------

--
-- Table structure for table `teachersdetail`
--

CREATE TABLE `teachersdetail` (
  `staffId` varchar(10) NOT NULL,
  `username` varchar(30) NOT NULL,
  `email` varchar(30) NOT NULL,
  `passcode` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `teachersdetail`
--

INSERT INTO `teachersdetail` (`staffId`, `username`, `email`, `passcode`) VALUES
('kjhj', ';;;;;', 'lll@jhhg', 'jjkk'),
('teacher12', 'remick', 'remick@gmail.com', 'remick123'),
('tr12', 'trs', 'trs@gmail', '1112'),
('tr128', 'kaye', 'kayegrace14@gmail.com', '123456'),
('tr33', 'trs', 'trs@gmail.com', '1111');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `asssignmentdetails`
--
ALTER TABLE `asssignmentdetails`
  ADD PRIMARY KEY (`assignmentId`);

--
-- Indexes for table `pupilsdetails`
--
ALTER TABLE `pupilsdetails`
  ADD PRIMARY KEY (`userCode`);

--
-- Indexes for table `scores`
--
ALTER TABLE `scores`
  ADD PRIMARY KEY (`assignmentId`,`userCode`);

--
-- Indexes for table `teachersdetail`
--
ALTER TABLE `teachersdetail`
  ADD PRIMARY KEY (`staffId`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `asssignmentdetails`
--
ALTER TABLE `asssignmentdetails`
  MODIFY `assignmentId` int(3) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT for table `scores`
--
ALTER TABLE `scores`
  MODIFY `assignmentId` int(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=47;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
