-- Bernardo Cavanellas Biondini
-- 20.1.4112

variables P Q R S A B: Prop.

lemma exL (H1 : P → Q)(H2: R → S): (P ∨ R) → (Q ∨ S) :=

  assume H: (P ∨ R),
  or.elim H (assume HI : P, show Q ∨ S, from or.intro_left S (H1 (show P, from HI)))
            (assume HI : R, show Q ∨ S, from or.intro_right Q (H2 (show R, from HI))).

lemma exM (H1 : Q → R): (P → Q) → (P → R) :=

  assume H: P → Q,
  assume HI: P,
  show R, from(H1 (show Q, from(H HI))).

lemma exA (H1 : ¬ (A ∨ B)): ¬A ∧ ¬B :=

  and.intro (assume H2: A, show false, from(H1 (or.intro_left B H2)))
            (assume H3: B, show false, from(H1 (or.intro_right A H3))).

lemma exB (H1 : ¬A ∧ ¬B):  ¬(A ∨ B) :=

assume H2: A ∨ B, show false, from(or.elim H2(assume H3: A, 
                                              show false, from(and.elim_left H1) H3)
                                              (assume H4: B,
                                              show false, from(and.elim_right H1) H4)).

