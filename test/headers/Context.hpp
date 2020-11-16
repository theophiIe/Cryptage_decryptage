
#pragma once
#include <iostream>
#include <QObject>

/**
 * @brief Contexte principale de l'application
 * 
 */
class Context : public QObject {

    Q_OBJECT

private:
    std::string prenom, nom;

    Context()
    {
        prenom = "Thukisdo";
        nom = "SEND NUDES MDR";
    }

public:

    /**
     * @brief Get the Singleton
     * 
     * @return Context& 
     */
    static Context& getInstance()
    {
        static Context singleton;
        return singleton;
    }

    // Pour s'assurer que la classe reste en Singleton
    Context(Context const&) = delete;
    Context& operator=(Context const&) = delete;

    /**
     * @brief Get the Prenom object
     *
     * @return std::string&
     */
    std::string& getPrenom() { return prenom; }
    /**
     * @brief Set the Prenom
     *
     * @param val
     */
    void setPrenom(std::string const& val)
    {
        prenom = val;
        emit prenomChanged();
    }
    /**
     * @brief Get the Nom
     *
     * @return std::string
     */
    std::string getNom() { return nom; };

    /**
     * @brief Set the Nom
     *
     * @param val
     */
    void setNom(std::string const& val)
    {
        nom = val;
        emit nomChanged();
    }

public slots:

    /**
     * @brief Reset le nom
     *
     */
    void resetNom()
    {
        setNom("SEND NUDES MDR");
    }

    /**
     * @brief Reset le prenom
     *
     */
    void resetPrenom()
    {
        setPrenom("Thukisdo");
    }

signals:
    /**
     * @brief Emitted when the nom changed
     *
     */
    void nomChanged();
    /**
     * @brief Emitted when the prenom changed
     *
     */
    void prenomChanged();
};