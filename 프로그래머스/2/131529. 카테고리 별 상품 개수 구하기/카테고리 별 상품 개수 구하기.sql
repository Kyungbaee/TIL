SELECT SUBSTRING(PRODUCT_CODE FROM 1 FOR 2) AS CATEGORY, SUM(1) AS PRODUCTS
FROM PRODUCT
GROUP BY CATEGORY
ORDER BY CATEGORY