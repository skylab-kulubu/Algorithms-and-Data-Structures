# Hash Table
Hash Tablosu, verileri ilişkisel bir şekilde depolayan bir veri yapısıdır. Hash tablosunda, her veri değeri kendi benzersiz dizin değerine sahip bir dizi biçiminde depolanır. Aranan verinin dizinini bildiğimiz takdirde veriye erişim çok hızlı hale gelir.

Böylece, verinin boyutundan bağımsız olarak ekleme ve arama işlemlerinin çok hızlı gerçekleştiği bir veri yapısı haline gelir. Hash Tablosu, bir depolama ortamı olarak bir dizi kullanır ve bir öğenin hangi dizine ekleneceği veya nereden bulunacağı, bir hash tekniği kullanarak oluşturulan bir indeks kullanır.

## Hash table karmaşıklığı: arama (search), ekleme (insert), silme (delete)

All: amortized O(1), worst O(n)

[#complexity](complexity.md) [#hashtable](Hash_Table.md)

## Hash table gerçekleştirilmesi
Bir hash tablosu anahtarları(key) değerlerle(value) eşleştiren bir veri yapısıdır. Bir dizi anahtar değeri bir dizinin bir dizi dizinine dönüştürme tekniğidir. Anahtarları değerlerle eşleştirebilen bir yapı olan ilişkilendirilebilir bir dizi uygulamak için kullanılır. Bir Karma Tablosu (hash table), bir dizini, istenen değerin bulunabileceği bir grup veya yuva dizisi halinde hesaplamak için bir karma işlevi kullanır. Wikipedia’dan.

![hash table](https://miro.medium.com/v2/resize:fit:720/format:webp/1*3jxEppESh9LLK14YMQ-ocA.png)

- Linked list olarak dizi
- Dizi dizinini belirlemek için hash kodu fonksiyonu

Bir eşik değeri aşıldığında dizi boyutunu yeniden boyutlandırın

Eğer aşırı dengesiz bir dağılım varsa, BST dizisi ile değiştirilebilir.

[#hashtable](hashtable.md)
