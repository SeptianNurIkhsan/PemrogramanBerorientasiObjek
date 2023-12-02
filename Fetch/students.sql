CREATE TABLE IF NOT EXISTS `students` (
    `id` int(11) NOT NULL,
    `fullname` varchar(191) NOT NULL,
    `email` varchar(191) NOT NULL,
    `phone` varchar(20) NOT NULL,
    `course` varchar(20) NOT NULL,
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;