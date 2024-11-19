class Test {
    private:
        int x;
        int y;
    public:
        Test(int x, int y) {
            this->x = x;
            this->y = y;
        }
        int sum() {
            return this->x + this->y;
        }
};