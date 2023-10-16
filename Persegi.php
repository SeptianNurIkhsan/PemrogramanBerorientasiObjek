<?php

require_once 'BangunDatar.php';

class Persegi extends BangunDatar {
    private $sisi;

    public function __construct($sisi) {
        $this->sisi = $sisi;
    }

    public function hitungLuas() {
        return $this->sisi * $this->sisi;
    }

    public function hitungKeliling() {
        return 4 * $this->sisi;
    }
}

?>