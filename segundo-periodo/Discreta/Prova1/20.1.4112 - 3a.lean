variables A B C D : Prop.

-- substitua o comando sorry pelo texto
-- de sua demonstração.

lemma ex3a (H : A → (B ∨ C))
   : ¬ B → (A → C)
   := 
   assume H1: ¬B, 
   assume H2: A,

        have H3: B ∨ C, from H H2,

        show C,
        from (or.elim H3 
                    (assume H4: B,
                        show C, 
                        from false.elim(H1 H4))
                    (assume H5: C, H5)).
