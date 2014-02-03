#ifndef CRACKER_H
#define CRACKER_H


class Cracker
{
    public:
        Cracker();
        virtual ~Cracker();
        bool cracker( Empreinte y, ArcEnCiel aec, Contexte ctxt, String & clair );

    protected:
    private:
};

#endif // CRACKER_H
