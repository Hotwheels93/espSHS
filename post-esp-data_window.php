<?php

$servername = "localhost";
$dbname = "YOUR_DB_NAME";
$username = "YOUR_DB_USER";
$password = "YOUR_DB_PW";

$api_key_value = "1234567890987654321";

$api_key= $sensor = $location = $value1 = "";



if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $api_key = test_input($_POST["api_key"]);
    if($api_key == $api_key_value) {
        $sensor = test_input($_POST["sensor"]);
        $location = test_input($_POST["location"]);
        $value1 = test_input($_POST["value1"]);
        // Create connection
        $conn = new mysqli($servername, $username, $password, $dbname);
        // Check connection
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        } 
        
        $sql = "UPDATE WindowStatus SET value1 = '$value1' WHERE location = '$location'";
        if ($conn->query($sql) === TRUE) {

            echo "Window Status: ";
            echo $value1;
            echo " ";
            echo "New record created successfully";
        } 
        else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }
    
        $conn->close();
    }
    else {
        echo "Wrong API Key provided.";
    }

}
else {
    echo "No data posted with HTTP POST.";
}

function test_input($data) {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}
