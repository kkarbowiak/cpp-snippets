#ifndef SECRET_H
#define SECRET_H

class Secret
{
    public:
        class ConstructorKey
        {
            private:
                ConstructorKey() {};

                friend class SecretFactory;
        };

    public:
        explicit Secret(int value, ConstructorKey) : mData(value) {} // accessed only with a key

    private:
        void setData(int value) { mData = value; } // only private access

    private:
        int mData;
};

class SecretFactory
{
    public:
        Secret getSecret(int value) { return Secret(value, Secret::ConstructorKey()); }
};

#endif /* SECRET_H */
