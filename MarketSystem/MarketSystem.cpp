#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>
#include <locale.h>

using namespace std;

const int urun_sayisi = 50;

int main()
{
    setlocale(LC_ALL, "Turkish");
    // urun.txt
    int urun_kodu;
    string urun_adi;
    string ureticisi;
    string temin_suresi;
    string uretim_tarihi;
    float fiyat_genel_musteri;
    float fiyat_ozel_musteri;
    float kdv_orani;
    int stok_adedi;

    // cari.txt
    int firma_no;
    string firma_adi;
    string firma_telefon;
    string firma_sorumlusu;
    string musteri_gatagorisi_genel;
    string musteri_gatagorisi_ozel;
    string adres;

    // siparis.txt
    int firma_noS;
    string siparis_tarihi;
    float siparis_tutari_genel;
    float siparis_tutari_ozel;
    int siparis_listesi_dosyasi_urun;
    int siparis_listesi_dosyasi_adet;
    string siparis_alan;

    int secim;
    char cevap;

    cout << "\t\t\t|MARKET|\n\t\t\t*******\n1) ürün islemler. \n"
        << "2) müsteri islemler. \n"
        << "3) siparis islemleri. \n"
        << "4) çikis. \n";
    cin >> secim;
    // iþlem seçmek
    switch (secim)
    {
    case 1:
    {
        cout << "\n\n1) urun ekleme. \n";
        cout << "2) urun arama. \n";
        cout << "3) urun listeleme. \n";
        cout << "4) urun duzeltme. \n";
        cout << "5) urun silme. \n";
        cin >> secim;
        switch (secim)
        {
            //ürün eklemek
        case 1:
        {
            ofstream dosya_yaz("urun.txt", ios::app);
            do
            {
                srand(time(NULL));
                urun_kodu = (rand() % (9999 - 1000 + 1) + 1000);
                cout << "\n\nurun kodu: " << urun_kodu << endl;
                cout << "urun adi giriniz:";
                cin >> urun_adi;
                cout << "ureticisi adi giriniz:";
                cin >> ureticisi;
                cout << "temin suresi giriniz:";
                cin >> temin_suresi;
                cout << "uretim tarihi giriniz:";
                cin >> uretim_tarihi;
                cout << "fiyat(genel) giriniz:";
                cin >> fiyat_genel_musteri;
                cout << "fiyat(ozel) giriniz:";
                cin >> fiyat_ozel_musteri;
                cout << "kdv orani giriniz:";
                cin >> kdv_orani;
                cout << "stok adedi giriniz:";
                cin >> stok_adedi;
                dosya_yaz << "\n"
                    << urun_kodu << " " << urun_adi << " " << ureticisi << " " << temin_suresi << " " << uretim_tarihi << " " << fiyat_genel_musteri << " " << fiyat_ozel_musteri << " " << kdv_orani << " " << stok_adedi;
                cout << "\ndevam etmek istiyormusunuz[e/h]:\n";
                cin >> cevap;
            } while (cevap == 'e' || cevap == 'E');
            dosya_yaz.close();
            cout << "\ndosyaya yazmak tamamlandi.\n"
                << endl;
        }
        break;
        //ürün aramak
        case 2:
        {
            do
            {
                ifstream dosya_oku("urun.txt");
                int aranan_kodu;
                cout << "\nurun kodu yaz: ";
                cin >> aranan_kodu;
                while (!dosya_oku.eof())
                {
                    dosya_oku >> urun_kodu >> urun_adi >> ureticisi >> temin_suresi >> uretim_tarihi >> fiyat_genel_musteri >> fiyat_ozel_musteri >> kdv_orani >> stok_adedi;
                    if (aranan_kodu == urun_kodu)
                    {
                        cout << "\nurun kodu :" << urun_kodu << endl;
                        cout << "urun adi :" << urun_adi << endl;
                        cout << "ureticisi adi :" << ureticisi << endl;
                        cout << "temin suresi :" << temin_suresi << endl;
                        cout << "uretim tarihi :" << uretim_tarihi << endl;
                        cout << "fiyat(genel) :" << fiyat_genel_musteri << endl;
                        cout << "fiyat(ozel) :" << fiyat_ozel_musteri << endl;
                        cout << "kdv orani :" << kdv_orani << endl;
                        cout << "stok adedi :" << stok_adedi << endl;
                    }
                }
                cout << "\n devam etmek için [e/h] \n";
                cin >> cevap;

                dosya_oku.close();
            } while (cevap == 'e' || cevap == 'E');
        }
        break;
        // tüm ürünler gösterme
        case 3:
        {
            ifstream dosya_oku("urun.txt");
            while (!dosya_oku.eof())
            {
                dosya_oku >> urun_kodu >> urun_adi >> ureticisi >> temin_suresi >> uretim_tarihi >> fiyat_genel_musteri >> fiyat_ozel_musteri >> kdv_orani >> stok_adedi;
                cout << "\nurun kodu: " << urun_kodu << endl;
                cout << "urun adi :" << urun_adi << endl;
                cout << "ureticisi adi :" << ureticisi << endl;
                cout << "temin suresi :" << temin_suresi << endl;
                cout << "uretim tarihi :" << uretim_tarihi << endl;
                cout << "fiyat(genel) :" << fiyat_genel_musteri << endl;
                cout << "fiyat(ozel) :" << fiyat_ozel_musteri << endl;
                cout << "kdv orani :" << kdv_orani << endl;
                cout << "stok adedi :" << stok_adedi << endl
                    << endl
                    << endl;
            }
            dosya_oku.close();
        }
        break;
        //ürün düzeltme
        case 4:
        {
            int duzeltme_kodu;
            cout << "\nduzeltmek urun kodu giriniz: ";
            cin >> duzeltme_kodu;
            ifstream dosya_oku("urun.txt");
            ofstream dosya_yaz("urun.tmp");
            while (!dosya_oku.eof())
            {
                dosya_oku >> urun_kodu >> urun_adi >> ureticisi >> temin_suresi >> uretim_tarihi >> fiyat_genel_musteri >> fiyat_ozel_musteri >> kdv_orani >> stok_adedi;
                if (duzeltme_kodu == urun_kodu)
                {
                    cout << "\neski urun bilgileri\n";
                    cout << "eski urun kodu : " << urun_kodu << endl;
                    cout << "eski urun adi :" << urun_adi << endl;
                    cout << "eski ureticisi adi :" << ureticisi << endl;
                    cout << "eski temin suresi :" << temin_suresi << endl;
                    cout << "eski uretim tarihi :" << uretim_tarihi << endl;
                    cout << "eski fiyat(genel) :" << fiyat_genel_musteri << endl;
                    cout << "eski fiyat(ozel) :" << fiyat_ozel_musteri << endl;
                    cout << "eski kdv orani :" << kdv_orani << endl;
                    cout << "eski stok adedi :" << stok_adedi << endl;

                    cout << "\nyeni bilgiler giriniz\n";

                    cout << "yeni urun kodu: " << urun_kodu;
                    cout << "\nyeni urun adi giriniz:";
                    cin >> urun_adi;
                    cout << "yeni ureticisi adi giriniz:";
                    cin >> ureticisi;
                    cout << "yeni temin suresi giriniz:";
                    cin >> temin_suresi;
                    cout << "yeni uretim tarihi giriniz:";
                    cin >> uretim_tarihi;
                    cout << "yeni fiyat(genel) giriniz:";
                    cin >> fiyat_genel_musteri;
                    cout << "yeni fiyat(ozel) giriniz:";
                    cin >> fiyat_ozel_musteri;
                    cout << "yeni kdv orani giriniz:";
                    cin >> kdv_orani;
                    cout << "yeni stok adedi giriniz:";
                    cin >> stok_adedi;

                    dosya_yaz << "\n"
                        << urun_kodu << " " << urun_adi << " " << ureticisi << " " << temin_suresi << " " << uretim_tarihi << " " << fiyat_genel_musteri << " " << fiyat_ozel_musteri << " " << kdv_orani << " " << stok_adedi;
                }
                else
                {
                    dosya_yaz << "\n"
                        << urun_kodu << " " << urun_adi << " " << ureticisi << " " << temin_suresi << " " << uretim_tarihi << " " << fiyat_genel_musteri << " " << fiyat_ozel_musteri << " " << kdv_orani << " " << stok_adedi;
                }
            }
            dosya_yaz.close();
            dosya_oku.close();

            remove("urun.txt");
            rename("urun.tmp", "urun.txt");
        }
        break;
        //ürün silme
        case 5:
        {
            do
            {
                int silen_urun;
                cout << "\nsilenecek urun kodu giriniz: ";
                cin >> silen_urun;
                ifstream dosya_oku("urun.txt");
                ofstream dosya_yaz("urun.tmp");

                while (!dosya_oku.eof())
                {
                    dosya_oku >> urun_kodu >> urun_adi >> ureticisi >> temin_suresi >> uretim_tarihi >> fiyat_genel_musteri >> fiyat_ozel_musteri >> kdv_orani >> stok_adedi;

                    if (silen_urun != urun_kodu)
                    {
                        dosya_yaz << "\n"
                            << urun_kodu << " " << urun_adi << " " << ureticisi << " " << temin_suresi << " " << uretim_tarihi << " " << fiyat_genel_musteri << " " << fiyat_ozel_musteri << " " << kdv_orani << " " << stok_adedi;
                    }
                }
                cout << "\ndevam etmek için [e/h]:\n";
                cin >> cevap;
                dosya_yaz.close();
                dosya_oku.close();

                remove("urun.txt");
                rename("urun.tmp", "urun.txt");
            } while (cevap == 'e' || cevap == 'E');
        }
        break;
        default:
            break;
        }
    }
    break;
    case 2:
    {
        cout << "\n1) musteri ekle." << endl;
        cout << "2) musteri arama." << endl;
        cout << "3) musteri duzeltme. " << endl;
        cout << "4) musteri silme." << endl;
        cin >> secim;
        switch (secim)
        {
            // müþteri eklemek
        case 1:
        {
            ofstream dosya_yaz("cari.txt", ios::app);
            do
            {
                firma_no = (rand() % (9999 - 1000 + 1) + 1000);
                cout << "\nfirma kodu: " << firma_no << endl;
                cout << "firma adi giriniz: ";
                cin >> firma_adi;
                cout << "firma telefonu giriniz: ";
                cin >> firma_telefon;
                cout << "firma sorumlusu giriniz: ";
                cin >> firma_sorumlusu;
                cout << "musteri gatagorisi(genel) giriniz: ";
                cin >> musteri_gatagorisi_genel;
                cout << "musteri gatagorisi(ozel) giriniz: ";
                cin >> musteri_gatagorisi_ozel;
                cout << "firma adresi giriniz: ";
                cin >> adres;
                dosya_yaz << "\n"
                    << firma_no << " " << firma_adi << " " << firma_telefon << " " << firma_sorumlusu << " "
                    << musteri_gatagorisi_genel << " " << musteri_gatagorisi_ozel << " " << adres;
                cout << "\ndevam etmek istiyormusunuz[e/h]:\n";
                cin >> cevap;
            } while (cevap == 'e' || cevap == 'E');
            dosya_yaz.close();
            cout << "\ndosyaya yazmak tamamlandi.\n"
                << endl;
        }
        break;
        // müþteri aramak
        case 2:
        {
            do
            {
                ifstream dosya_oku("cari.txt");
                int aranan_kodu;
                cout << "\nfirma kodu yaz:";
                cin >> aranan_kodu;
                while (!dosya_oku.eof())
                {
                    dosya_oku >> firma_no >> firma_adi >> firma_telefon >> firma_sorumlusu >> musteri_gatagorisi_genel >> musteri_gatagorisi_ozel >> adres;
                    if (aranan_kodu == firma_no)
                    {
                        cout << "\nfirma kodu: " << firma_no << endl;
                        cout << "firma adi :" << firma_adi << endl;
                        cout << "firma telefonu :" << firma_telefon << endl;
                        cout << "firma sorumlusu :" << firma_sorumlusu << endl;
                        cout << "musteri gatagorisi(genel) :" << musteri_gatagorisi_genel << endl;
                        cout << "musteri gatagorisi(ozel) :" << musteri_gatagorisi_ozel << endl;
                        cout << "firma adresi :" << adres << endl;
                    }
                }
                cout << "\n devam etmek için [e/h]: \n";
                cin >> cevap;
                dosya_oku.close();
            } while (cevap == 'e' || cevap == 'E');
        }
        break;
        // müþteri düzeltme
        case 3:
        {
            int duzeltme_kodu;
            cout << "\nduzeltmek firma kodu giriniz: ";
            cin >> duzeltme_kodu;
            ifstream dosya_oku("cari.txt");
            ofstream dosya_yaz("cari.tmp");
            while (!dosya_oku.eof())
            {
                dosya_oku >> firma_no >> firma_adi >> firma_telefon >> firma_sorumlusu >> musteri_gatagorisi_genel >> musteri_gatagorisi_ozel >> adres;
                if (duzeltme_kodu == firma_no)
                {
                    cout << "\neski firma bilgileri\n";
                    cout << "eski firma kodu : " << firma_no << endl;
                    cout << "eski firma adi :" << firma_adi << endl;
                    cout << "eski firma telefonu :" << firma_telefon << endl;
                    cout << "eski firma sorumlusu :" << firma_sorumlusu << endl;
                    cout << "eski musteri gatagorisi(genel) :" << musteri_gatagorisi_genel << endl;
                    cout << "eski musteri gatagorisi(ozel) :" << musteri_gatagorisi_ozel << endl;
                    cout << "eski firma adresi :" << adres << endl;

                    cout << "\nyeni bilgiler giriniz\n";

                    cout << "yeni firma kodu: " << firma_no << endl;
                    cout << "yeni firma adi giriniz:";
                    cin >> firma_adi;
                    cout << "yeni firma telefonu giriniz:";
                    cin >> firma_telefon;
                    cout << "yeni firma sorumlusu giriniz:";
                    cin >> firma_sorumlusu;
                    cout << "yeni musteri gatagorisi(genel) giriniz:";
                    cin >> musteri_gatagorisi_genel;
                    cout << "yeni musteri gatagorisi(ozel) giriniz:";
                    cin >> musteri_gatagorisi_ozel;
                    cout << "yeni firma adresi giriniz:";
                    cin >> adres;

                    dosya_yaz << "\n"
                        << firma_no << " " << firma_adi << " " << firma_telefon << " " << firma_sorumlusu << " " << musteri_gatagorisi_genel << " " << musteri_gatagorisi_ozel << " " << adres;
                }
                else
                {
                    dosya_yaz << "\n"
                        << firma_no << " " << firma_adi << " " << firma_telefon << " " << firma_sorumlusu << " " << musteri_gatagorisi_genel << " " << musteri_gatagorisi_ozel << " " << adres;
                }
            }
            dosya_yaz.close();
            dosya_oku.close();

            remove("cari.txt");
            rename("cari.tmp", "cari.txt");
        }
        break;
        // müþteri silme
        case 4:
        {
            do
            {
                int silen_firma;
                cout << "\nsilenecek firma kodu giriniz: ";
                cin >> silen_firma;
                ifstream dosya_oku("cari.txt");
                ofstream dosya_yaz("cari.tmp");

                while (!dosya_oku.eof())
                {
                    dosya_oku >> firma_no >> firma_adi >> firma_telefon >> firma_sorumlusu >> musteri_gatagorisi_genel >> musteri_gatagorisi_ozel >> adres;

                    if (silen_firma != firma_no)
                    {
                        dosya_yaz << "\n"
                            << firma_no << " " << firma_adi << " " << firma_telefon << " " << firma_sorumlusu << " " << musteri_gatagorisi_genel << " " << musteri_gatagorisi_ozel << " " << adres;
                    }
                }
                cout << "\ndevam etmek için [e/h]:\n";
                cin >> cevap;
                dosya_yaz.close();
                dosya_oku.close();

                remove("cari.txt");
                rename("cari.tmp", "cari.txt");
            } while (cevap == 'e' || cevap == 'E');
            cout << "\ndosya selinmistir.\n";
        }
        break;
        default:
            break;
        }
    }
    break;
    case 3:
    {
        cout << "\n1) sipars olustur.\n";
        cout << "2) siparis arama.\n";
        cout << "3) siparis silme.\n";
        cout << "4) siparis duzeltme.\n";
        cout << "5) siparis raporlama.\n";
        cin >> secim;
        switch (secim)
        {
            // sipariþ oluþturmak
        case 1:
        {
            ofstream dosya_yaz2("siparis.txt", ios::app);
            do
            {
                int x;
                int y = 0;
                ifstream dosya_oku3("cari.txt");
                cout << "\nfirma kodu giriniz: ";
                cin >> firma_noS;
                while (!dosya_oku3.eof())
                {
                    dosya_oku3 >> firma_no >> firma_adi >> firma_telefon >> firma_sorumlusu >> musteri_gatagorisi_genel >> musteri_gatagorisi_ozel >> adres;
                    if (firma_no == firma_noS)
                        y = 1;
                }
                if (y == 0)
                {
                    cout << "\n\nFÝRMA NUMARASI BULUNMAMAS. :(\n\n";
                    exit(0);
                }
                dosya_oku3.close();
                cout << "siparis tarihi giriniz: ";
                cin >> siparis_tarihi;
                cout << "siparis alani giriniz: ";
                cin >> siparis_alan;
                {
                    ifstream dosya_oku("urun.txt");
                    while (!dosya_oku.eof())
                    {
                        dosya_oku >> urun_kodu >> urun_adi >> ureticisi >> temin_suresi >> uretim_tarihi >> fiyat_genel_musteri >> fiyat_ozel_musteri >> kdv_orani >> stok_adedi;
                        cout << "\nurun kodu: " << urun_kodu << endl;
                        cout << "urun adi :" << urun_adi << endl;
                        cout << "temin suresi :" << temin_suresi << endl;
                        cout << "uretim tarihi :" << uretim_tarihi << endl;
                        cout << "fiyat(genel) :" << fiyat_genel_musteri << endl;
                        cout << "fiyat(ozel) :" << fiyat_ozel_musteri << endl;
                        cout << "kdv orani :" << kdv_orani << endl;
                        cout << "stok adedi :" << stok_adedi << endl
                            << endl
                            << endl;
                        x = stok_adedi;
                    }
                    dosya_oku.close();
                }
                cout << "\n\ntutacaksizin urunler lutfen kodlari ve kaç adet giriniz:\n\n";
                cout << "urun kodu: ";
                cin >> siparis_listesi_dosyasi_urun;
                cout << "kaç adet: ";
                cin >> siparis_listesi_dosyasi_adet;
                if (siparis_listesi_dosyasi_adet > x)
                {
                    cout << "\n\nyeterli adetler yok.\n\n";
                    exit(0);
                }
                ifstream dosya_oku("urun.txt");
                {
                    ofstream dosya_yaz("urun.tmp");
                    while (!dosya_oku.eof())
                    {
                        dosya_oku >> urun_kodu >> urun_adi >> ureticisi >> temin_suresi >> uretim_tarihi >> fiyat_genel_musteri >> fiyat_ozel_musteri >> kdv_orani >> stok_adedi;

                        if (siparis_listesi_dosyasi_urun == urun_kodu)
                        {
                            stok_adedi -= siparis_listesi_dosyasi_adet;
                            dosya_yaz << "\n"
                                << urun_kodu << " " << urun_adi << " " << ureticisi << " " << temin_suresi << " " << uretim_tarihi << " " << fiyat_genel_musteri << " " << fiyat_ozel_musteri << " " << kdv_orani << " " << stok_adedi;
                        }
                        else
                        {
                            dosya_yaz << "\n"
                                << urun_kodu << " " << urun_adi << " " << ureticisi << " " << temin_suresi << " " << uretim_tarihi << " " << fiyat_genel_musteri << " " << fiyat_ozel_musteri << " " << kdv_orani << " " << stok_adedi;
                        }
                    }
                    dosya_yaz.close();
                }
                while (!dosya_oku.eof())
                {
                    if (siparis_listesi_dosyasi_urun == urun_kodu)
                    {
                        dosya_oku >> urun_kodu >> urun_adi >> ureticisi >> temin_suresi >> uretim_tarihi >> fiyat_genel_musteri >> fiyat_ozel_musteri >> kdv_orani >> stok_adedi;
                    }
                }
                siparis_tutari_genel = fiyat_genel_musteri * siparis_listesi_dosyasi_adet * (kdv_orani / 100);
                siparis_tutari_ozel = fiyat_ozel_musteri * siparis_listesi_dosyasi_adet * (kdv_orani / 100);
                dosya_yaz2 << "\n"
                    << firma_noS << " " << siparis_tarihi << " " << siparis_alan << " " << siparis_listesi_dosyasi_urun
                    << " " << siparis_listesi_dosyasi_adet << " " << siparis_tutari_genel << " " << siparis_tutari_ozel;
                cout << "tutar(genel): " << siparis_tutari_genel << endl;
                cout << "tutar(ozel): " << siparis_tutari_ozel << endl;
                dosya_yaz2.close();
                dosya_oku.close();

                remove("urun.txt");
                rename("urun.tmp", "urun.txt");
                cout << "\ndevam etmek istiyormusunuz[e/h]:\n";
                cin >> cevap;
            } while (cevap == 'e' || cevap == 'E');
        }
        break;
        // sipariþ aramak
        case 2:
        {
            do
            {
                ifstream dosya_oku("siparis.txt");
                int aranan_siparis;
                cout << "\nsiparis kodu yaz: ";
                cin >> aranan_siparis;
                while (!dosya_oku.eof())
                {
                    dosya_oku >> firma_noS >> siparis_tarihi >> siparis_alan >> siparis_listesi_dosyasi_urun >> siparis_listesi_dosyasi_adet >> siparis_tutari_genel >> siparis_tutari_ozel;
                    if (aranan_siparis == firma_noS)
                    {
                        cout << "\nfirma kodu: " << firma_noS << endl;
                        cout << "siparis tarihi :" << siparis_tarihi << endl;
                        cout << "siparis alan :" << siparis_alan << endl;
                        cout << "siparis urunun kodu :" << siparis_listesi_dosyasi_urun << endl;
                        cout << "siparis urunun adeti :" << siparis_listesi_dosyasi_adet << endl;
                        cout << "tutar(genel) :" << siparis_tutari_genel << endl;
                        cout << "tutar(ozel) :" << siparis_tutari_ozel << endl;
                    }
                }
                cout << "\n devam etmek için [e/h]: \n";
                cin >> cevap;
                dosya_oku.close();
            } while (cevap == 'e' || cevap == 'E');
        }
        break;
        // sipariþ silmek
        case 3:
        {
            do
            {
                int silen_siparis;
                cout << "\nsilenecek siparis kodu giriniz: ";
                cin >> silen_siparis;
                ifstream dosya_oku("siparis.txt");
                ofstream dosya_yaz("siparis.tmp");
                ifstream dosya_oku2("urun.txt");
                ofstream dosya_yaz2("urun.tmp");
                while (!dosya_oku.eof())
                {
                    dosya_oku >> firma_noS >> siparis_tarihi >> siparis_alan >> siparis_listesi_dosyasi_urun >> siparis_listesi_dosyasi_adet >> siparis_tutari_genel >> siparis_tutari_ozel;
                    dosya_oku2 >> urun_kodu >> urun_adi >> ureticisi >> temin_suresi >> uretim_tarihi >> fiyat_genel_musteri >> fiyat_ozel_musteri >> kdv_orani >> stok_adedi;
                    if (silen_siparis == firma_noS)
                    {
                        stok_adedi += siparis_listesi_dosyasi_adet;
                        dosya_yaz2 << "\n"
                            << urun_kodu << " " << urun_adi << " " << ureticisi << " " << temin_suresi << " " << uretim_tarihi << " " << fiyat_genel_musteri << " " << fiyat_ozel_musteri << " " << kdv_orani << " " << stok_adedi;
                    }
                    if (silen_siparis != firma_noS)
                    {
                        dosya_yaz2 << "\n"
                            << urun_kodu << " " << urun_adi << " " << ureticisi << " " << temin_suresi << " " << uretim_tarihi << " " << fiyat_genel_musteri << " " << fiyat_ozel_musteri << " " << kdv_orani << " " << stok_adedi;
                        dosya_yaz << "\n"
                            << firma_noS << " " << siparis_tarihi << " " << siparis_alan << " " << siparis_listesi_dosyasi_urun << " " << siparis_listesi_dosyasi_adet << " " << siparis_tutari_genel << " " << siparis_tutari_ozel;
                        dosya_yaz2.close();
                    }
                }
                cout << "\ndevam etmek için [e/h]:\n";
                cin >> cevap;
                dosya_yaz.close();
                dosya_oku.close();
                dosya_oku2.close();
                dosya_yaz2.close();

                remove("urun.txt");
                rename("urun.tmp", "urun.txt");
                remove("siparis.txt");
                rename("siparis.tmp", "siparis.txt");
            } while (cevap == 'e' || cevap == 'E');
            cout << "\n\siparis selinmistir.\n\n";
        }
        break;
        // sipariþ düzeltme
        case 4:
        {
            int duzeltme_kodu;
            cout << "\nduzeltmek siparis kodu giriniz: ";
            cin >> duzeltme_kodu;
            ifstream dosya_oku("siparis.txt");
            ofstream dosya_yaz("siparis.tmp");
            while (!dosya_oku.eof())
            {
                dosya_oku >> firma_noS >> siparis_tarihi >> siparis_alan >> siparis_listesi_dosyasi_urun >> siparis_listesi_dosyasi_adet >> siparis_tutari_genel >> siparis_tutari_ozel;
                if (duzeltme_kodu == firma_noS)
                {
                    cout << "\neski siparis bilgileri\n";
                    cout << "eski firma kodu : " << firma_noS << endl;
                    cout << "eski siparis tarihi :" << siparis_tarihi << endl;
                    cout << "eski siparis alan :" << siparis_alan << endl;
                    cout << "eski siparis urunun kodu :" << siparis_listesi_dosyasi_urun << endl;
                    cout << "eski siparis urunun adedi :" << siparis_listesi_dosyasi_adet << endl;
                    cout << "eski tutar(genel) :" << siparis_tutari_genel << endl;
                    cout << "eski tutar(ozel) :" << siparis_tutari_ozel << endl;

                    cout << "\nyeni bilgiler giriniz\n";

                    cout << "yeni firma kodu: " << firma_noS;
                    cout << "yeni siparis tarihi giriniz:";
                    cin >> siparis_tarihi;
                    cout << "yeni siparis alan giriniz:";
                    cin >> siparis_alan;
                    cout << "yeni siparis urunun kodu giriniz:";
                    cin >> siparis_listesi_dosyasi_urun;
                    cout << "yeni siparis urunun adedi giriniz:";
                    cin >> siparis_listesi_dosyasi_adet;

                    dosya_yaz << "\n"
                        << firma_noS << " " << siparis_tarihi << " " << siparis_alan << " " << siparis_listesi_dosyasi_urun << " " << siparis_listesi_dosyasi_adet << " " << siparis_tutari_genel << " " << siparis_tutari_ozel;
                }
                else
                {
                    dosya_yaz << "\n"
                        << urun_kodu << " " << urun_adi << " " << ureticisi << " " << temin_suresi << " " << uretim_tarihi << " " << fiyat_genel_musteri << " " << fiyat_ozel_musteri << " " << kdv_orani << " " << stok_adedi;
                }
            }
            dosya_yaz.close();
            dosya_oku.close();

            remove("siparis.txt");
            rename("siparis.tmp", "siparis.txt");
        }
        break;
        // tüm sipariþler gösterme
        case 5:
        {
            ifstream dosya_oku("siparis.txt");
            while (!dosya_oku.eof())
            {
                dosya_oku >> firma_noS >> siparis_tarihi >> siparis_alan >> siparis_listesi_dosyasi_urun >> siparis_listesi_dosyasi_adet >> siparis_tutari_genel >> siparis_tutari_ozel;
                cout << "\nurun kodu: " << firma_noS << endl;
                cout << "urun adi :" << siparis_tarihi << endl;
                cout << "ureticisi adi :" << siparis_alan << endl;
                cout << "temin suresi :" << siparis_listesi_dosyasi_urun << endl;
                cout << "uretim tarihi :" << siparis_listesi_dosyasi_adet << endl;
                cout << "fiyat(genel) :" << siparis_tutari_genel << endl;
                cout << "fiyat(ozel) :" << siparis_tutari_ozel << endl
                    << endl
                    << endl;
            }
            dosya_oku.close();
        }
        break;
        default:
            break;
        }
    }
    break;
    case 4:
        exit(0);
        break;
    default:
        break;
    }
}
