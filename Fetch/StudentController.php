<?php

class StudentController
{
    private $conn;

    public function __construct($db)
    {
        $this->conn = $db->getConnection();
    }

     public function edit($id)
    {
        $student_id = mysqli_real_escape_string($this->conn, $id);
        $studentQuery = "SELECT * FROM students WHERE id='$student_id' LIMIT 1";
        $result = $this->conn->query($studentQuery);
        if($result->num_rows == 1){
            $data = $result->fetch_assoc();
            return $data;
        }else{
            return false;
        }
    }

    public function update($inputData, $id)
    {
        $student_id = mysqli_real_escape_string($this->conn, $id);
        $fullname = $inputData['fullname'];
        $email = $inputData['email'];
        $phone = $inputData['phone'];
        $course = $inputData['course'];

        $studentQuery = "UPDATE students SET fullname='$fullname', email='$email', phone='$phone', course='$course' WHERE id='$student_id' LIMIT 1";
        $result = $this->conn->query($studentQuery);
        if($result){
            return true;
        }else{
            return false;
        }
    }

     public function delete($id)
    {
        $student_id = mysqli_real_escape_string($this->conn,$id);
        $studentDeleteQuery = "DELETE FROM students WHERE id='$student_id' LIMIT 1";
        $result = $this->conn->query($studentDeleteQuery);
        if($result){
            return true;
        }else{
            return false;
        }
    }

    public function index()
    {
        $studentQuery = "SELECT * FROM students";
        $result = $this->conn->query($studentQuery);

        if ($result === false) {
            // Penanganan kesalahan saat menjalankan kueri
            die("Error executing query: " . $this->conn->error);
        }

        if ($result->num_rows > 0) {
            // Mengembalikan array asosiatif dari hasil kueri
            return $result->fetch_all(MYSQLI_ASSOC);
        } else {
            return [];
        }
    }
}
?>