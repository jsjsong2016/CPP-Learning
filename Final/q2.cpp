int &value() {
        return num;
    }
    void operator+(Number &n) {
        this->num += n.num;
    }
