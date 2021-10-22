-- questão 3 b.

variable U : Type.         -- universo de discurso
variable a : U.            -- garante que o universo é não vazio.


-- predicados

variables F G H : U → Prop.

-- substitua o comando sorry pelo texto
-- de sua demonstração.

lemma ex3b (H1 : ∃ x, F x ∨ G x)
           (H2 : ∀ x, F x → H x)
           (H3 : ∀ x, G x → H x) : ∃ x, H x
           := 
          assume a, 
                have Hfog: F a ∨ G a, from exists.elim H1 
                (assume Hn : F a ∨ G a, Hn), 

                have Hfh: F a → H a, from H2 a,
                have Hgh : G a → H a, from H3 a,

                show H a, 
                from (or.elim Hfog
                        (assume Hf: F a,
                            show H a,
                            from Hfh Hf)

                        (assume Hg: G a,
                            show H a,
                            from Hgh Hg)).
lemma exD 
    (H1 : ∃ x, P x ∧ Q x) (H2 : ∀ x, P x → R x) : ∃ x, R x ∧ Q x := 
    
    assume a : U, 
    assume H3: P a ∧ Q a, 
        have Hrq: R a ∧ Q a, from exists.elim H1
        (assume Hra : R a ∧ Q a, Hra),

        have Hr: R a, from and.intro (have P a → R a, from H2 a, H2),
        have Hq: Q a, from and.intro (H3).
