<?php
include('dbconn.php');
include_once('StudentController.php');

$db = new DatabaseConnection;

if (!$db || !$db->conn) {
    die("Database connection is not established.");
}

$student_id = mysqli_real_escape_string($db->conn, $_POST['student_id']);

if(isset($_POST['update_student']))
{
    $id = mysqli_real_escape_string($db->conn,$_POST['student_id']);
    $inputData = [
        'fullname' => mysqli_real_escape_string($db->conn,$_POST['fullname']),
        'email' => mysqli_real_escape_string($db->conn,$_POST['email']),
        'phone' => mysqli_real_escape_string($db->conn,$_POST['phone']),
        'course' => mysqli_real_escape_string($db->conn,$_POST['course']),
    ];
    $student = new StudentController($db);
    $result = $student->update($inputData, $id);

    if($result)
    {
        $_SESSION['message'] = "Student Added Successfully";
        header("Location: student-view.php");
        exit(0);
    }
    else
    {
        $_SESSION['message'] = "Student Not Added";
        header("Location: student-view.php");
        exit(0);
    }
}

if(isset($_POST['deleteStudent']))
{
    $id = mysqli_real_escape_string($db->conn, $_POST['deleteStudent']);
    $student = new StudentController($db);
    $result = $student->delete($id);
    if($result)
    {
        $_SESSION['message'] = "Student Added Successfully";
        header("Location: student-view.php");
        exit(0);
    }
    else
    {
        $_SESSION['message'] = "Student Not Added";
        header("Location: student-view.php");
        exit(0);
    }
}

?>