<?php

require_once 'Persegi.php';
require_once 'PersegiPanjang.php';
require_once 'Segitiga.php';
require_once 'Lingkaran.php';

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $jenisBangunDatar = $_POST['jenis'];

    if ($jenisBangunDatar == 'persegi') {
        $sisi = $_POST['sisi'];
        $bangunDatar = new Persegi($sisi);
    } elseif ($jenisBangunDatar == 'persegi_panjang') {
        $panjang = $_POST['panjang'];
        $lebar = $_POST['lebar'];
        $bangunDatar = new PersegiPanjang($panjang, $lebar);
    } elseif ($jenisBangunDatar == 'segitiga') {
        $alas = $_POST['alas'];
        $tinggi = $_POST['tinggi'];
        $bangunDatar = new Segitiga($alas, $tinggi);
    } elseif ($jenisBangunDatar == 'lingkaran') {
        $jari = $_POST['jari'];
        $bangunDatar = new Lingkaran($jari);
    }

    $luas = $bangunDatar->hitungLuas();
    $keliling = $bangunDatar->hitungKeliling();
}

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Hitung Luas dan Keliling Bangun Datar</title>
</head>

<body>
    <h1>Hitung Luas dan Keliling Bangun Datar</h1>
    <form method="post" action="">
        <label for="jenis">Jenis Bangun Datar:</label>
        <select name="jenis" id="jenis">
            <option value="persegi">Persegi</option>
            <option value="persegi_panjang">Persegi Panjang</option>
            <option value="segitiga">Segitiga</option>
            <option value="lingkaran">Lingkaran</option>
        </select>
        <br>

        <!-- Tampilkan input sesuai jenis bangun datar -->
        <label for="sisi">Sisi:</label>
        <input type="text" name="sisi" id="sisi">
        <br>

        <label for="panjang">Panjang:</label>
        <input type="text" name="panjang" id="panjang">
        <br>

        <label for="lebar">Lebar:</label>
        <input type="text" name="lebar" id="lebar">
        <br>

        <label for="alas">Alas:</label>
        <input type="text" name="alas" id="alas">
        <br>

        <label for="tinggi">Tinggi:</label>
        <input type="text" name="tinggi" id="tinggi">
        <br>

        <label for="jari">Jari-Jari:</label>
        <input type="text" name="jari" id="jari">
        <br>

        <button type="submit">Hitung</button>
    </form>

    <?php
    if (isset($luas) && isset($keliling)) {
        echo "<h2>Hasil:</h2>";
        echo "Luas: $luas <br>";
        echo "Keliling: $keliling <br>";
    }
    ?>
</body>

</html>