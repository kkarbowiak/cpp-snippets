#include "secret.h"


int main()
{
    SecretFactory sf;

    Secret s = sf.getSecret(42);
}
